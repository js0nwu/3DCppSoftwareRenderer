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
	this->frame = new float[render_width*render_height*3];
	player = new transform();
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

void engine::cls() {
	for (int i = 0; i < render_width*render_height*3; i++) {
		this->frame[i] = (float) 0;
	}
}

void engine::start() {
	printf("engine started\n");
	this->initialize();
}

void engine::stop() {
	this->cleanup();
}

void engine::render() {
	vector3* delta = new vector3(1, 1, 1);
	player->translate(delta);
	delete delta;
	this->cls(); //clear screen;
	for (int i = 0; i < this->scene.things.size(); i++) {
		thing* t = this->scene.things[i];
		mesh* m = t->get_mesh();
		for (int j = 0; j < m->vertices.size(); j++) {
			matrix4* move = this->player->get_projected_transformation();
			vector4* point = new vector4(m->vertices[j]->get_position());
			point->multiply_first(move);
			if (point->get_x() >= 0 && point->get_x() < 800 && point->get_y() >= 0 && point->get_y() < 600) {
				int index = camera::get_index_3d(point->get_x(), point->get_y(), 0, 800, 3);
				this->frame[index] = 1;
				this->frame[index + 1] = 1;
				this->frame[index + 2] = 1;
			}
			delete move;
			delete point;
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

