//
// Created by taehoon on 5/24/21.
//

#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::mouseClicked(T &obj, sf::RenderWindow &window) {
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds = obj.getGlobalBounds();
    return bounds.contains(mouse);
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow& window) {
    if (sf::Mouse::getPosition().x < window.getSize().x || sf::Mouse::getPosition().x > 0) {} else { return false; }
    if (sf::Mouse::getPosition().y < window.getSize().y || sf::Mouse::getPosition().y > 0) {} else { return false; }
    return true;
}

template<class T>
bool MouseEvents<T>::mouseHover(T obj, sf::RenderWindow& window) {
    sf::FloatRect bounds = obj.getGlobalBounds();
    return bounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}