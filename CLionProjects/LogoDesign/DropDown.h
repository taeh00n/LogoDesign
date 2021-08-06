//
// Created by taehoon on 4/29/21.
//

#ifndef MIDTERM_DROPDOWN_H
#define MIDTERM_DROPDOWN_H

#include <list>
#include "States.h"
#include "TextBox.h"
#include "MouseEvents.h"
#include "TextInput.h"

class DropDown {
private:
  std::vector<Textbox*> textbox;
  int width;
  int posx;
  int posy;
public:
    std::string label;
    void initiate(std::vector<std::string> boxNames, int length, int width, int posx, int posy, std::string title) {
        this->posx = posx;
        this->posy = posy;
        this->width = width;
        auto* holder = new Textbox;
        holder->setSize(length, width);
        holder->getRectAdd().setOutlineThickness(2);
        holder->setLabel(title);
        int outline = holder->getRect().getOutlineThickness();
        holder->setPosition(posx + outline, posy + outline);
        int new_size = length * 0.5;
        holder->getLabel().setCharacterSize(new_size);
        textbox.push_back(holder);
        for(int i = 0; i < boxNames.size(); i++) {
            holder = new Textbox;
            holder->setLabel(boxNames[i]);
            holder->setPosition(posx + outline, (i+1)*width + outline + posy);
            holder->setSize(length, width);
            holder->moveLabel(posx + holder->getRect().getGlobalBounds().width/2.0f + outline, posy + (i+2)*width - outline);
            holder->getLabel().setCharacterSize(new_size - 10);
            textbox.push_back(holder);
        }
    }
    void mouseHover(sf::RenderWindow& window) {
        for(auto & i : textbox) {
            if(MouseEvents<sf::RectangleShape>::mouseHover(i->getRect(), window)) {
                i->getRectAdd().setFillColor(sf::Color::Blue);
            } else {
                i->getRectAdd().setFillColor(sf::Color::Transparent);
            }
        }
    }
    void changeLabel(sf::RenderWindow& window, bool option) {
        if(textbox[0]->getStates().active(CLICK)) {
            for(int i = 1; i < textbox.size(); i++) {
                textbox[i]->updateClickLocation(window);
                if(textbox[i]->getWithinBox()) {
                    label = textbox[i]->getLabel().getString();
                    if(option) {
                        textbox[0]->setLabel(label);
                        textbox[0]->moveLabel(textbox[0]->getRect().getGlobalBounds().width / 2.0f + 2 + posx,
                                              posy + width - 2);
                    }
                }
            }
        }
    }
    std::vector<Textbox*> getTextbox() {
        return textbox;
    }
    std::vector<Textbox*> getTextboxConst() const {
        return textbox;
    }
};

#endif //MIDTERM_DROPDOWN_H
