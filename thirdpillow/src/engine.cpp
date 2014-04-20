/*
 * engine.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: jwpilly
 */

#include "engine.h"

world* engine::get_scene() {
	return &this->scene;
}

camera* engine::get_main_camera() {
	return this->cameras[this->main_camera];
}

void engine::create_camera() {
	camera* c = new camera(this->render_width, this->render_height);
	this->cameras.push_back(c);
}

void engine::create_camera(vector3 position, vector3 rotation, vector3 scale) {
	//create a camera here;
	camera* c = new camera(this->render_width, this->render_height);
	this->cameras.push_back(c);
}

void engine::add_camera(camera* c) {
	this->cameras.push_back(c);
}

void engine::cleanup() {
	printf("cleaning up\n");
}

float engine::RandomFloat(float a, float b) {
	float random = ((float) rand()) / (float) RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

void engine::initialize() {
	printf("engine initializing\n");
	this->main_camera = 0;
	mesh* m = new mesh();
	for (int i = 0; i < 5000; i++) {
		vector3* vertexp = new vector3(RandomFloat(0, 10), RandomFloat(0, 10),
				RandomFloat(0, 10));
		m->vertices.push_back(new vertex(*vertexp));
	}
	thing* t = new thing();
	t->set_mesh(m);
	this->scene.things.push_back(t);
}

void engine::start() {
	printf("engine started\n");
	this->initialize();
}

void engine::stop() {
	this->cleanup();
}

void engine::render() {
	for (int i = 0; i < this->cameras.size(); i++) {
		if (this->cameras[i]->is_active()) {
			this->cameras[i]->render(&this->scene);
			this->frame = this->cameras[i]->get_frame();
		}
	}
}

float* engine::get_render_buffer() {
	return this->frame;
}

engine::engine(int render_width, int render_height) {
	printf("engine created (%d, %d)\n", render_width, render_height);
	this->render_width = render_width;
	this->render_height = render_height;
}

engine::~engine() {
	printf("stopping engine\n");
	this->stop();
}

