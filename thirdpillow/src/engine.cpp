#include "engine.h"

camera* cam;

world engine::get_scene() {
    return this->scene;
}

void engine::cleanup() {
    printf("cleaning up\n");
    delete this->frame;
}

void engine::initialize() {
    printf("engine initializing\n");
    color default_color(1, 0, 0, 1);
    rast = new rasterizer(default_color);
    player = new transform();
    cam = new camera(this->frame->get_width(), this->frame->get_height());
    transform::set_camera(cam);
    vector3* start = new vector3(-20, 0, 0);
    cam->set_position(start);
    transform::set_projection((float)70, (float) this->frame->get_width(), this->frame->get_height(), (float) 1, (float)1000);
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
    this->scene.things.push_back(t);
    this->scene.things.push_back(t2);
    this->scene.things.push_back(t3);
}

void engine::start() {
    printf("engine started\n");
    this->initialize();
}

void engine::stop() {
    this->cleanup();
}

void engine::render() {
    this->frame->cls();
    for (int i = 0; i < this->scene.things.size(); i++) {
        thing* t = this->scene.things[i];
        mesh m = t->get_mesh();
        image texture = t->get_texture();
        matrix4 mt = t->t.get_projected_transformation();
        this->rast->draw_mesh_textured(*this->frame, m, texture, mt);
    }
}

float* engine::get_render_buffer() {
    return this->frame->get_buffer();
}

engine::engine(int render_width, int render_height) {
    printf("engine created (%d, %d)\n", render_width, render_height);
    this->frame = new screen(render_width, render_height);
}

engine::~engine() {
    printf("stopping engine\n");
    this->stop();
}

