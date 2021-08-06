//
// Created by taehoon on 5/27/21.
//

#include "ColorPickerMenu.h"

ColorPickerMenu::ColorPickerMenu(float posX, float posY, std::string label) {
    this->posX = posX;
    this->posY = posY;
    initiateCurrentColor(label);
    initiateColorMenu();
    initiateColorOptions();
}

ColorPickerMenu::ColorPickerMenu() {}

void ColorPickerMenu::initiateCurrentColor(std::string label) {
    currentColor.setPosition(posX, posY);
    currentColor.setFillColor(sf::Color::Red);
    currentColor.setSize({30, 30});
    textColor.setFont(Fonts::getFont(Fonts::ARIAL));
    textColor.setString(label);
    textColor.setCharacterSize(15);
    textColor.setPosition({posX - textColor.getLocalBounds().width - 20, posY + 5});
}

void ColorPickerMenu::initiateColorMenu() {
    colorMenu.setPosition(posX, posY + currentColor.getSize().y);
    colorMenu.setFillColor(sf::Color(128, 128, 128));
    colorMenu.setSize({170, 90});
}

void ColorPickerMenu::initiateColorOptions() {
    colorOptions[0].setSize({30, 30});
    colorOptions[0].setPosition(posX + 10, posY + 10 + currentColor.getSize().y + currentColor.getOutlineThickness());
    for (int i = 1; i < 4; i++) {
        colorOptions[i].setSize({30, 30});
        colorOptions[i].setPosition(colorOptions[i - 1].getPosition().x + colorOptions[i - 1].getSize().x + 10,
                                    colorOptions[i - 1].getPosition().y);
    }
    for (int i = 4; i < 8; i++) {
        colorOptions[i].setSize({30, 30});
        colorOptions[i].setPosition(colorOptions[i - 4].getPosition().x,
                                    colorOptions[i - 4].getPosition().y + colorOptions[0].getSize().y + 10);
    }
    colorOptions[0].setFillColor(sf::Color::Magenta);
    colorOptions[1].setFillColor(sf::Color::Red);
    colorOptions[2].setFillColor(sf::Color::Green);
    colorOptions[3].setFillColor(sf::Color::Blue);
    colorOptions[4].setFillColor(sf::Color::Yellow);
    colorOptions[5].setFillColor(sf::Color::White);
    colorOptions[6].setFillColor(sf::Color::Cyan);
    colorOptions[7].setFillColor(sf::Color::Black);

    colorPicker(0.33);
}

void ColorPickerMenu::colorPicker(double hue) {
    sf::VertexArray box(sf::Points, 256 * 256);
    points = box;
    for (int y = 0; y <= 255; y++) {
        for (int x = 0; x <= 255; x++) {
            int index = y * 256 + x;
            points[index].position.x = x;
            points[index].position.y = y;
            double s = x/255.;
            double v = y/255.;

            int cs = hue * 6;

            double f = hue * 6 - cs;
            double p = v * (1 - s);
            double q = v * (1 - s * f);
            double t = v * (1 - s * (1 - f));


            switch (cs) {
                case 0:
                case 6:
                    points[index].color = sf::Color(v * 255, t * 255, p * 255);
                    break;
                case 1:
                    points[index].color = sf::Color(q * 255, v * 255, p * 255);
                    break;
                case 2:
                    points[index].color = sf::Color(p * 255, v * 255, t * 255);
                    break;
                case 3:
                    points[index].color = sf::Color(p * 255, q * 255, v * 255);
                    break;
                case 4:
                    points[index].color = sf::Color( t * 255, p * 255, v * 255);
                    break;
                case 5:
                    points[index].color = sf::Color(v * 255, p * 255, q * 255);
                    break;
            }
        }
    }
}

void ColorPickerMenu::switchColor(sf::Color color) {
    if(color == sf::Color::Red) {
        colorPicker(0);
    } else if(color == sf::Color::Green) {
        colorPicker(0.33);
    } else if(color == sf::Color::Blue) {
        colorPicker(0.62);
    } else if(color == sf::Color::Yellow) {
        colorPicker(0.1667);
    } else if(color == sf::Color::White) {
        color = sf::Color::White;
        currentColor.setFillColor(color);
    } else if(color == sf::Color::Cyan) {
        colorPicker(0.5);
    } else if(color == sf::Color::Black) {
        color = sf::Color::Black;
        currentColor.setFillColor(color);
    } else if(color == sf::Color::Magenta) {
        colorPicker(0.833);
    }
}

void ColorPickerMenu::pickColor(sf::Vector2i pos) {
    color = points[pos.y * 256 + pos.x].color;
    currentColor.setFillColor(color);
}