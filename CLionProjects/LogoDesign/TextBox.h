//
// Created by taehoon on 4/11/21.
//

#ifndef MIDTERM_TEXTBOX_H
#define MIDTERM_TEXTBOX_H

#include "MouseEvents.h"
#include "States.h"
#include "Fonts.h"

class Textbox {
private:
    bool within_box = false;
    bool within_window = false;
    sf::Text text;
    States State;
    std::string label;
    sf::RectangleShape rect;
public:
    Textbox() {
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineThickness(1);
    }
    void setSize(float x, float y) {
        rect.setSize(sf::Vector2f(x, y));
    }
    void setPosition(int x, int y) {
        rect.setPosition(x, y);
    }
    void setLabel(std::string label) {
        text.setFont(Fonts::getFont(Fonts::ARIAL));
        text.setString(label);
        text.setCharacterSize(15);
        text.setPosition(rect.getPosition().x, rect.getPosition().y - 10 - text.getCharacterSize());
    }
    void moveLabel(float x, float y) {
        text.setOrigin(rect.getLocalBounds().width/2.0f, rect.getLocalBounds().height/2.0f);
        text.setPosition(x, y);
    }
    void updateClickLocation(sf::RenderWindow& window) {
        if(MouseEvents<sf::RectangleShape>::mouseClicked(rect, window)) {
            within_box = true;
            rect.setOutlineColor(sf::Color::Blue);
        } else if(MouseEvents<sf::RectangleShape>::mouseClicked(window)) {
            within_window = true; within_box = false;
            rect.setOutlineColor(sf::Color::Yellow);
        } else {
            within_box = false; within_window = false;
        }
    }
    States& getStates() {
        return State;
    }
    States getStatesConst() const {
        return State;
    }
    sf::Text getLabel() const {
        return text;
    }
    sf::RectangleShape getRect() {
        return rect;
    }
    sf::RectangleShape getRect() const {
        return rect;
    }
    sf::RectangleShape& getRectAdd() {
        return rect;
    }
    bool getWithinBox() const {
        return within_box;
    }
};

#endif //MIDTERM_TEXTBOX_H
