//
// Created by taehoon on 5/27/21.
//

#ifndef FINAL_COLORPICKERMENU_H
#define FINAL_COLORPICKERMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MouseEvents.h"
#include "Fonts.h"

class ColorPickerMenu {
private:
    void initiateCurrentColor(std::string label);
    void initiateColorMenu();
    void initiateColorOptions();
    void colorPicker(double hue);
    float posX;
    float posY;
public:
    ColorPickerMenu(float posX, float posY, std::string label);
    ColorPickerMenu();
    void switchColor(sf::Color color);
    void pickColor(sf::Vector2i pos);
    sf::VertexArray points;
    sf::RectangleShape currentColor;
    sf::RectangleShape colorMenu;
    sf::RectangleShape colorOptions[8];
    sf::Color color;
    sf::Text textColor;
    bool openMenu = false;
    bool openPoints = false;
};


#endif //FINAL_COLORPICKERMENU_H
