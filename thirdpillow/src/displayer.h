#ifndef PROJECT_DISPLAYER_H
#define PROJECT_DISPLAYER_H

#include <SDL.h>
#include "screen.h"
#include <stdio.h>

class displayer {
public:
    displayer(const char* title, screen* frame);
    void refresh();
    virtual ~displayer();
private:
    const char* title;
    screen* frame;
    void initialize();
    void cleanup();

    SDL_Window* sdl_window;
    SDL_Renderer* sdl_renderer;
    SDL_Texture* sdl_texture;
    SDL_Surface* sdl_surface;
    SDL_Surface* frame_surface;
};


#endif //PROJECT_DISPLAYER_H
