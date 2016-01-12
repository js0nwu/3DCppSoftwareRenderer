#include "engine.h"

camera* cam;

void engine::cleanup() {
    printf("cleaning up\n");
    delete frame;
}

void engine::load() {
    color default_color(255, 0, 0, 255);
    rast = new rasterizer(default_color);
    player = new t_transform();
    cam = new camera(frame->get_width(), frame->get_height());
    t_transform::set_camera(cam);
    vector3* start = new vector3(-20, 0, 0);
    cam->set_position(start);
    t_transform::set_projection((float)70, (float) frame->get_width(), frame->get_height(), (float) 1, (float)1000);
    game_input->inputs.push_back(cam);
    mesh m;
    m.from_obj("res/testgolem.obj");
    mesh m2;
    m2.from_obj("res/testalduinsmall.obj");
    image texture;
    texture.from_ppm_raw("res/testgolem.ppm");
    image texture2;
    texture2.from_ppm_raw("res/alduin_lod.ppm");
    thing* t = new thing();
    t->set_mesh(m);
    t->set_texture(texture);
    t->t.set_scale(1, 1, 1);
    thing* t2 = new thing();
    t2->set_mesh(m2);
    t2->set_texture(texture2);
    t2->t.set_scale(2, 2, 2);
    t2->t.set_translation(20, 0, 0);
    mesh m3;
    m3.from_obj("res/testplane.obj");
    image texture3;
    texture3.from_ppm_raw("res/testkoala.ppm");
    thing* t3 = new thing();
    t3->set_mesh(m3);
    t3->set_texture(texture3);
    t3->t.set_translation(0, -5, 0);
    //scene.things.push_back(t);
    scene.things.push_back(t2);
    //scene.things.push_back(t3);
}

void engine::initialize() {
    game_clock = new timekeeper();
    game_clock->start();
    timel = 0;
    game_input = new inputter();
    screen_display = new displayer("thirdpillow", frame);
    printf("engine initializing\n");
}

void engine::start() {
    printf("engine started\n");
    initialize();
    load();
    game_loop = true;
    loop();
}

void engine::stop() {
    game_loop = false;
    cleanup();
}

void engine::input(SDL_Event e) {
    game_input->refresh(e);
}

void engine::display() {
    screen_display->refresh();
}

void engine::render() {
    long ge = game_clock->get_ticks();
    if (ge - timel >= 1000) {
        long timediff = ge - timel;
        float fps = frames * 1000.f / timediff;
        printf("fps: %4.2f\n", fps);
        timel = ge;
        frames = 0;
    }
    frame->cls();
    for (int i = 0; i < scene.things.size(); i++) {
        thing* t = scene.things[i];
        mesh m = t->get_mesh();
        image texture = t->get_texture();
        matrix4 mt = t->t.get_projected_t_transformation();
        rast->draw_mesh_textured(*frame, m, texture, mt);
    }
    frames++;
}

void engine::loop() {
    SDL_Event e;
    while (game_loop) {
        while (SDL_PollEvent(&e) != 0) {
            input(e);
            if (e.type == SDL_QUIT) {
                game_loop = false;
            }
        }
        render();
        display();
    }
}

engine::engine(int render_width, int render_height, int fps) {
    printf("engine created (%d, %d, %d)\n", render_width, render_height, fps);
    frame = new screen(render_width, render_height);
    fps = fps;
}

engine::~engine() {
    printf("stopping engine\n");
    stop();
}

