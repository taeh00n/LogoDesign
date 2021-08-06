//
// Created by taehoon on 6/7/21.
//

#include "DropDownAction.h"

#include <utility>

void DropDownAction::closeProject() {}

void DropDownAction::newProject() {}

std::string DropDownAction::openProject(DropDownMenu menu){
    sf::RenderWindow window(sf::VideoMode(800, 600), "");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for (int j = 0; j < menu.getMenu().size(); j++) {
                DropDown index = menu.getMenu()[j];
                index.getTextbox()[0]->updateClickLocation(window);
                index.changeLabel(window, true);
                if (!index.label.empty()) {
                    window.close();
                    return index.label;
                }
                if (index.getTextbox()[0]->getWithinBox()) {
                    index.getTextbox()[0]->getStates().enable(CLICK);
                } else {
                    index.getTextbox()[0]->getStates().disable(CLICK);
                }
            }
        }
        for(int j = 0; j < menu.getMenu().size(); j++) {
            DropDown index = menu.getMenu()[j];
            index.mouseHover(window);
        }
        for(int j = 0; j < menu.getMenu().size(); j++) {
            DropDown index = menu.getMenu()[j];
            window.draw(index.getTextboxConst()[0]->getRect());
            window.draw(index.getTextboxConst()[0]->getLabel());
            if(index.getTextboxConst()[0]->getStatesConst().active(CLICK)) {
                for(int k = 0; k < index.getTextboxConst().size(); k++) {
                    window.draw(index.getTextboxConst()[k]->getRect());
                    window.draw(index.getTextboxConst()[k]->getLabel());
                }
            }
        }
        window.display();
    }
}
void DropDownAction::saveProject(sf::Text text, sf::RectangleShape background, sf::Text shadow, std::string font){
    std::string filename = "Logos/" + text.getString() + ".txt";
    std::ofstream outfile (filename);
    outfile << (std::string) text.getString() << std::endl;
    outfile << text.getCharacterSize() << std::endl;
    outfile << text.getPosition().x << std::endl;
    outfile << text.getPosition().y << std::endl;
    outfile << text.getScale().y << std::endl;
    outfile << shadow.getPosition().x << std::endl;
    outfile << shadow.getPosition().y << std::endl;
    outfile << static_cast<int>(text.getFillColor().r) << " " << static_cast<int>(text.getFillColor().g) << " " << static_cast<int>(text.getFillColor().b) << static_cast<int>(text.getFillColor().a) << std::endl;
    outfile << static_cast<int>(background.getFillColor().r) << " " << static_cast<int>(background.getFillColor().g) << " " << static_cast<int>(background.getFillColor().b) << static_cast<int>(background.getFillColor().a) << std::endl;
    outfile << static_cast<int>(shadow.getFillColor().a) << std::endl;
    outfile << font << std::endl;
    outfile.close();
}

void DropDownAction::exportPng(sf::Text shadow, sf::Text logo, sf::RectangleShape background) {
    sf::RenderTexture renderTexture;
    renderTexture.create(800, 300);
    renderTexture.clear(sf::Color::Black);
    background.move(0, -40);
    renderTexture.draw(background);
    renderTexture.draw(logo);
    renderTexture.draw(shadow);
    sf::Texture texture = renderTexture.getTexture();
    sf::Image save = texture.copyToImage();
    save.flipVertically();
    std::string filename = "image/" + logo.getString() + ".jpg";
    save.saveToFile(filename);
}
