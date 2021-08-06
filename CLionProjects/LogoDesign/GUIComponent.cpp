//
// Created by taehoon on 6/3/21.
//

#include "GUIComponent.h"

void GUIComponent::initiate() {
    Textbox box;
    box.setSize(250, 20);
    box.setPosition(30, 380);
    box.setLabel("Label");
    this->box = box;
    texts.textPrep(box.getRect().getPosition());

    sf::FloatRect textRect = logo.getLocalBounds();
    logo.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top + textRect.height/2.0f);
    background.setSize({800, 300});
    background.setPosition({0, 40});

    colors.emplace_back(400, 380, "Text Color:");
    colors.emplace_back(600, 380, "Background Color:");

    data.emplace_back(100, 150, 430, "Text Opacity", 255); //0
    data.emplace_back(100, 400, 430, "Font Size", 100); //1
    data.emplace_back(100, 150, 460, "Shadow Opacity", 255); //2
    data.emplace_back(255, 470, 460, "Background Opacity", 255); //3
    data.emplace_back(100, 150, 490, "Text X-Axis", 255); //4
    data.emplace_back(100, 380, 490, "Skew", 255); //5
    data.emplace_back(100, 150, 520, "Text Y-Axis", 255); //6
    data.emplace_back(100, 150, 550, "Shadow X-Axis", 255); //7
    data.emplace_back(100, 150, 580, "Shadow Y-Axis", 255); //8

    DropDownMenu menu, fontMenu;
    std::vector<std::vector<std::string>> labels = {{"Close Project", "New Project", "Open Project", "Quit", "Save Project"}, {"Export"}};
    menu.createMenu(labels, 110, 30, 0, 0, "File");
    std::vector<std::vector<std::string>> fonts = {{"Arcade", "Arial", "Open Sans Bold"}};
    fontMenu.createMenu(fonts, 110, 30, 670, 380, "Open Sans Bold");
    this->menu.push_back(menu);
    this->menu.push_back(fontMenu);

}

void GUIComponent::update(sf::RenderWindow &window) {
    for(Slider &i : data) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            i.moveSlider(window);
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        box.updateClickLocation(window);
        openDropDown(window);
    }
    for(auto &i : menu) {
        for(int j = 0; j < i.getMenu().size(); j++) {
            DropDown index = i.getMenu()[j];
            index.mouseHover(window);
        }
    }
    selectColor(window);
    texts.update();
    prepLogo();
    selectFont(menu[1].getMenu()[0].getTextbox()[0]->getLabel().getString());
    prepShadow();
}

void GUIComponent::prepLogo() {
    colors[0].color.a = data[0].value;
    logo.setFillColor(colors[0].color);
    colors[1].color.a = data[3].value;
    background.setFillColor(colors[1].color);

    logo.setCharacterSize(data[1].value);
    logo.setPosition(sf::Vector2f(data[4].value, data[6].value));
    logo.setString(texts.line);
}

void GUIComponent::prepShadow() {
    shadow = logo;
    shadow.scale(1.0f, -(0.1 * data[5].value));
    shadow.move(data[7].value, logo.getCharacterSize() * (0.1 * data[8].value));
    sf::Color color(shadow.getFillColor());
    color.a = data[2].value;
    shadow.setFillColor(color);
}

void GUIComponent::selectFont(std::string fontChoice) {
    currentFont = fontChoice;
    if(fontChoice == "Arcade") {
        logo.setFont(Fonts::getFont(Fonts::ARCADE));
    } else if(fontChoice == "Arial") {
        logo.setFont(Fonts::getFont(Fonts::ARIAL));
    } else if(fontChoice == "Open Sans Bold") {
        logo.setFont(Fonts::getFont(Fonts::OPENSANSBOLD));
    }
}

void GUIComponent::selectColor(sf::RenderWindow &window) {
    for(auto &i : colors) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(MouseEvents<sf::RectangleShape>::mouseClicked(i.currentColor, window)) {
                i.openMenu = true;
            }
            if(i.openMenu) {
                for(auto &j : i.colorOptions) {
                    if(MouseEvents<sf::RectangleShape>::mouseClicked(j, window)) {
                        i.openPoints = true;
                        i.switchColor(j.getFillColor());
                        if(j.getFillColor() == sf::Color::White || j.getFillColor() == sf::Color::Black) {
                            i.openMenu = false;
                            i.openPoints = false;
                        }
                    }
                }
            }
            if(i.openPoints) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if((sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= 255) &&
                       sf::Mouse::getPosition(window).y >= 0 && sf::Mouse::getPosition(window).y <= 255) {
                        i.pickColor(sf::Mouse::getPosition(window));
                        i.openMenu = false;
                        i.openPoints = false;
                    }
                }
            }
        }
    }
}

void GUIComponent::openDropDown(sf::RenderWindow &window) {
    for(int i = 0; i < menu.size(); i++) {
        for(int j = 0; j < menu[i].getMenu().size(); j++) {
            DropDown index = menu[i].getMenu()[j];
            index.getTextbox()[0]->updateClickLocation(window);
            index.changeLabel(window, true);
            if(!index.label.empty()) {
                if(index.label == "New Project") {
                    for(auto &i : data) {
                        i.resetSlider(0);
                    }
                    texts.line = "";
                } else if(index.label == "Open Project") {
                    DropDownMenu fileMenu;
                    std::vector<std::vector<std::string>> labels = {files};
                    fileMenu.createMenu(labels, 110, 30, 0, 0, "File");
                    std::ifstream infile("Logos/" + action.openProject(fileMenu));
                    int a, b, c, d;
                    std::string word;
                    infile >> word;
                    texts.line = word;
                    infile >> a;
                    data[1].resetSlider(a);
                    infile >> a >> b;
                    data[4].resetSlider(a);
                    data[6].resetSlider(b);
                    infile >> a;
                    data[5].resetSlider(a);
                    infile >> a >> b;
                    data[7].resetSlider(a);
                    data[8].resetSlider(b);
                    infile >> a >> b >> c >> d;
                    logo.setFillColor(sf::Color(a, b, c, d));
                    data[0].resetSlider(d);
                    infile >> a >> b >> c >> d;
                    background.setFillColor(sf::Color(a, b, c, d));
                    data[3].resetSlider(d);
                    infile >> d;
                    shadow.setFillColor(sf::Color(a,b,c,d));
                    data[2].resetSlider(d);
                    infile >> word;
                    selectFont(word);
                } else if(index.label == "Quit") {
                    window.close();
                } else if(index.label == "Save Project") {
                    files.push_back(logo.getString() + ".txt");
                    action.saveProject(logo, background, shadow, currentFont);
                } else if(index.label == "Export") {
                    action.exportPng(shadow, logo, background);
                }
            }
            if(index.getTextbox()[0]->getWithinBox()) {
                index.getTextbox()[0]->getStates().enable(CLICK);
            } else {
                index.getTextbox()[0]->getStates().disable(CLICK);
            }
        }
    }
}

void GUIComponent::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    texts.textProcess(event, box);
}

void GUIComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(logo);
    target.draw(shadow);
    for(const auto &i : data) {
        target.draw(i.text);
        target.draw(i.stat);
        target.draw(i.slide);
        target.draw(i.knob);
    }
    target.draw(texts.getString());
    target.draw(box.getLabel());
    target.draw(box.getRect());
    for(auto &i : colors) {
        target.draw(i.textColor);
        target.draw(i.currentColor);
        if(i.openMenu) {
            target.draw(i.colorMenu);
            for(auto &j : i.colorOptions) {
                target.draw(j);
            }
        }
        if(i.openPoints) {
            target.draw(i.points);
        }
    }
    for(auto &i : menu) {
        for(int j = 0; j < i.getMenu().size(); j++) {
            DropDown index = i.getMenu()[j];
            target.draw(index.getTextboxConst()[0]->getRect());
            target.draw(index.getTextboxConst()[0]->getLabel());
            if(index.getTextboxConst()[0]->getStatesConst().active(CLICK)) {
                for(int k = 0; k < index.getTextboxConst().size(); k++) {
                    target.draw(index.getTextboxConst()[k]->getRect());
                    target.draw(index.getTextboxConst()[k]->getLabel());
                }
            }
        }
    }
}
