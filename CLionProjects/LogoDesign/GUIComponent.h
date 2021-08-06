//
// Created by taehoon on 6/3/21.
//

#ifndef FINAL_GUICOMPONENT_H
#define FINAL_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "ColorPickerMenu.cpp"
#include "Slider.cpp"
#include "TextBox.h"
#include "TextInput.h"
#include "DropDown.h"
#include "DropDownMenu.h"
#include "DropDownAction.cpp"

class GUIComponent : public sf::Drawable {
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void prepShadow();
    void prepLogo();
    void selectFont(std::string fontChoice);
    void selectColor(sf::RenderWindow &window);
    void openDropDown(sf::RenderWindow &window);
    Textbox box;
    TextInput texts;
    std::vector<Slider> data;
    std::vector<ColorPickerMenu> colors;
    std::vector<DropDownMenu> menu;
    std::vector<std::string> files;
    std::string currentFont;
    DropDownAction action;
public:
    sf::RectangleShape background;
    sf::Text logo;
    sf::Text shadow;
    void initiate();
    void update(sf::RenderWindow &window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
};


#endif //FINAL_GUICOMPONENT_H
