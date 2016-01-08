#include "inputter.h"

inputter::inputter() {

}

void inputter::refresh(SDL_Event e) {
    for (inputtable* i : inputs) {
        i->input(e);
    }
}

inputter::~inputter() {

}