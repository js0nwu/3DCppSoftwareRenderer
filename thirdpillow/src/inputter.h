//
// Created by Jason Wu on 1/6/16.
//

#ifndef PROJECT_INPUTTER_H
#define PROJECT_INPUTTER_H

#include <vector>
#include <SDL.h>

#include "thing.h"

using namespace std;

class inputter {
public:
    inputter();
    vector<thing> inputs;
    void refresh();
    virtual ~inputter();
};


#endif //PROJECT_INPUTTER_H
