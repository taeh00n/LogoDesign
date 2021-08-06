//
// Created by taehoon on 5/24/21.
//

#ifndef FINAL_MOUSEEVENTS_H
#define FINAL_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>

template <class T>
class MouseEvents {
public:
    static bool mouseClicked(T& obj, sf::RenderWindow& window);
    static bool mouseClicked(sf::RenderWindow& window);
    static bool mouseHover(T obj, sf::RenderWindow& window);
};


#endif //FINAL_MOUSEEVENTS_H
