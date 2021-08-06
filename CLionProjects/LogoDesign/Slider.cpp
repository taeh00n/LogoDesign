//
// Created by taehoon on 5/24/21.
//

#include "Slider.h"
#include "Fonts.cpp"

Slider::Slider(float slideLength, float posX, float posY, const std::string& label, int max) {
    slide.setSize({slideLength,1});
    slide.setPosition(posX, posY);

    this->max = max;

    knob.setRadius(5);
    knob.setOrigin(knob.getRadius(), knob.getRadius());
    knob.setPosition(posX, posY);

    text.setFont(Fonts::getFont(Fonts::ARIAL));
    stat.setFont(Fonts::getFont(Fonts::ARIAL));
    text.setCharacterSize(15);
    stat.setCharacterSize(15);
    text.setString(label);
    text.setPosition({slide.getGlobalBounds().left - text.getGlobalBounds().width - 20, posY - (text.getCharacterSize()/2)});
    stat.setPosition({slide.getGlobalBounds().left + slide.getSize().x + 20, posY - (text.getCharacterSize()/2)});
}

void Slider::moveSlider(sf::RenderWindow &window) {
    if (MouseEvents<sf::CircleShape>::mouseClicked(knob, window)) {
        if (sf::Mouse::getPosition(window).x >= slide.getPosition().x &&
            sf::Mouse::getPosition(window).x <= slide.getPosition().x + slide.getSize().x) {
            knob.setPosition(sf::Mouse::getPosition(window).x, knob.getPosition().y);
            value = ((knob.getPosition().x - slide.getPosition().x) / slide.getSize().x) * max;
            stat.setString(std::to_string(value));
        }
    }
}

void Slider::resetSlider(int value) {
    knob.setPosition(((value * slide.getSize().x)/max) + slide.getPosition().x, knob.getPosition().y);
    stat.setString(std::to_string(value));
}