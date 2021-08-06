//
// Created by taehoon on 4/5/21.
//

#ifndef MIDTERM_STATES_H
#define MIDTERM_STATES_H

#include <map>

enum ObjectState {
    BLINK = false,
    CLICK = false,
    HOVER = false,
    LASTSTATE = false
};

class States {
private:
    std::map<ObjectState, bool> states = {{BLINK, false}, {CLICK, false}, {HOVER, false}, {LASTSTATE, false}};
public:
    bool active(ObjectState test) {
        return states[test];
    }
    void enable(ObjectState test) {
        states[test] = true;
    }
    void disable(ObjectState test) {
        states[test] = false;
    }
};


#endif //MIDTERM_STATES_H
