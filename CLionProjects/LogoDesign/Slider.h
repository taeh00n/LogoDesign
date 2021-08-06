//
// Created by taehoon on 5/24/21.
//

#ifndef FINAL_SLIDER_H
#define FINAL_SLIDER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "MouseEvents.h"

class Slider {
private:
public:
    int value = 1;
    Slider(float slideLength, float posX, float posY, const std::string& label, int max);
    void moveSlider(sf::RenderWindow &window);
    void resetSlider(int value);
    sf::RectangleShape slide;
    sf::CircleShape knob;
    sf::Text text;
    sf::Text stat;
    int max;
};


#endif //FINAL_SLIDER_H
