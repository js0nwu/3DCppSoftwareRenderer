//
// Created by Jason Wu on 1/8/16.
//

#ifndef PROJECT_INPUTTABLE_H
#define PROJECT_INPUTTABLE_H

#include <SDL.h>

class inputtable {
public:
    virtual void input(SDL_Event e) = 0;
    virtual ~inputtable() {}
};


#endif //PROJECT_INPUTTABLE_H
