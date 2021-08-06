//
// Created by taehoon on 6/5/21.
//

#ifndef FINAL_FONTS_H
#define FINAL_FONTS_H

#include <SFML/Graphics.hpp>

class Fonts {
public:
    enum fonts { OPENSANSBOLD, ARIAL, ARCADE, LAST};
    static sf::Font& getFont(fonts font);
private:
    static std::vector<sf::Font> fontsHolder;
    static std::vector<bool> loaded;
    static std::string mapFont(fonts font);
    static void loadFont(fonts font);
};


#endif //FINAL_FONTS_H
