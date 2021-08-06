//
// Created by taehoon on 5/9/21.
//

#ifndef MIDTERM_DROPDOWNMENU_H
#define MIDTERM_DROPDOWNMENU_H

#include <list>
#include "States.h"
#include "TextBox.h"

class DropDownMenu {
private:
    std::vector<DropDown> menu;
    DropDown col;
public:
    std::vector<DropDown> getMenu() const {
        return menu;
    }
    void createMenu(std::vector<std::vector<std::string>> labels, int length, int width, int posx, int posy, std::string title) {
        auto* col = new DropDown;
        col->initiate(labels[0], length, width, posx, posy, title);
        menu.push_back(*col);
        for(int i = 1; i < labels.size(); i++) {
            col = new DropDown;
            int pos_x = (i*length) + posx + 2;
            col->initiate(labels[i], length, width, pos_x, posy, title);
            menu.push_back(*col);
        }
    }
};
#endif //MIDTERM_DROPDOWNMENU_H
