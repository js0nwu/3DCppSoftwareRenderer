#ifndef ENGINE_H_
#define ENGINE_H_

#include <stdio.h>
#include <stdlib.h>

#include "displayer.h"
#include "vector3.h"
#include "vector4.h"
#include "t_transform.h"
#include "world.h"
#include "vertex.h"
#include "rasterizer.h"
#include "putils.h"
#include "screen.h"
#include "rasterizer.h"
#include "camera.h"
#include "image.h"
#include "inputter.h"
#include "timekeeper.h"

class engine {
public:
    void start();
    void stop();
    engine(int render_width, int render_height, int fps);
    virtual ~engine();
private:
    displayer* screen_display;
    inputter* game_input;
    timekeeper *game_clock;
    bool game_loop = false;
    int frames;
    long timel;
    world scene;
    t_transform* player;
    screen* frame;
    rasterizer* rast;
    void render();
    void input(SDL_Event e);
    void display();
    void loop();
    void initialize();
    void load();
    void cleanup();
};

#endif /* ENGINE_H_ */
