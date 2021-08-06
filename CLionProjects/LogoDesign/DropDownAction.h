//
// Created by taehoon on 6/7/21.
//

#ifndef FINAL_DROPDOWNACTION_H
#define FINAL_DROPDOWNACTION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "GUIComponent.h"
#include "DropDownMenu.h"

class DropDownAction {
public:
    void closeProject();
    void newProject();
    std::string openProject(DropDownMenu menu);
    void saveProject(sf::Text text, sf::RectangleShape background, sf::Text shadow, std::string font);
    void exportPng(sf::Text shadow, sf::Text logo, sf::RectangleShape background);
private:
};


#endif //FINAL_DROPDOWNACTION_H
