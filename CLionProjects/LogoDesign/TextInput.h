//
// Created by taehoon on 4/9/21.
//

#ifndef MIDTERM_TEXTINPUT_H
#define MIDTERM_TEXTINPUT_H

#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>

#include "TextBox.h"
#include "Fonts.h"

class TextInput {
private:
    sf::Text text;
    sf::Font font;
    float pos_x;
    float pos_y;
public:
    std::string line;
    void textPrep(sf::Vector2f box_pos) {
        pos_x = box_pos.x;
        pos_y = box_pos.y;
        text.setFont(Fonts::getFont(Fonts::ARIAL));
        text.setPosition(box_pos);
        text.setCharacterSize(15);
    }
    void textProcess(sf::Event event, Textbox box) {
        if(event.type == sf::Event::TextEntered && box.getWithinBox()) {
            if(event.text.unicode == 8 || event.text.unicode == 127) {
                line = line.substr(0, line.length()-1);
            } else if(event.text.unicode < 128) {
                line += event.text.unicode;
            }
        }
    }
    sf::Vector2f getPos() {
        return text.getPosition();
    }
    void update() {
        text.setString(line);
    }
    sf::Text getString() const {
        return text;
    }
};

#endif //MIDTERM_TEXTINPUT_H
