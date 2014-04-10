/*
 * engine.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: jwpilly
 */

#include "engine.h"

void engine::create_camera() {
	camera* c = new camera(this->render_width, this->render_height);
	this->cameras.push_back(c);
}

void engine::create_camera(vector3 position, vector3 rotation) {
	camera*c = new camera(this->render_width, this->render_height, position,
			rotation);
	this->cameras.push_back(c);
}

void engine::add_camera(camera* c) {
	this->cameras.push_back(c);
}

void engine::cleanup() {
	printf("cleaning up\n");
}

void engine::initialize() {
	printf("engine initializing\n");
	int size = this->render_width * this->render_height * 3;
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

