//
// Created by taehoon on 6/5/21.
//

#include "Fonts.h"

std::vector<sf::Font> Fonts::fontsHolder(LAST, sf::Font());
std::vector<bool> Fonts::loaded(LAST, false);

sf::Font &Fonts::getFont(Fonts::fonts font) {
    loadFont(font);
    return fontsHolder[font];
}

std::string Fonts::mapFont(Fonts::fonts font) {
    switch(font) {
        case OPENSANSBOLD: return "fonts/OpenSans-Bold.ttf";
        case ARIAL: return "fonts/arial.ttf";
        case ARCADE: return "fonts/Arcade.ttf";
    }
}

void Fonts::loadFont(Fonts::fonts font) {
    if(!loaded[font]) {
        fontsHolder[font].loadFromFile(mapFont(font));
        loaded[font] = true;
    }
}
