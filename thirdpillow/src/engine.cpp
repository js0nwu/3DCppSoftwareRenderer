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
	rast = new rasterizer();
	player = new transform();
	mesh* m = new mesh();
	for (int i = 0; i < 3; i++) {
		vector3* vertexp = new vector3(RandomFloat(0, 50), RandomFloat(0, 50),
				RandomFloat(0, 50));
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
	vector3* test_r = player->get_rotation();
	player->set_rotation(test_r->get_x() + 0.5, test_r->get_y() + 0.5,
			test_r->get_z() + 0.5);
	vector3* test_s = player->get_scale();
	player->set_scale(test_s->get_x() + 0.01, test_s->get_y() + 0.01, test_s->get_z() + 0.01);
	vector3* delta = new vector3(0.1, 0.1, 0.1);
	player->translate(delta);
	delete delta;
	this->frame->cls();
	for (int i = 0; i < this->scene.things.size(); i++) {
		thing* t = this->scene.things[i];
		mesh* m = t->get_mesh();
		for (int j = 0; j < m->vertices.size(); j++) {
			float distance =
					sqrt(
							(m->vertices[i]->get_position()->get_x()
									- player->get_translation()->get_x())
									* (m->vertices[i]->get_position()->get_x()
											- player->get_translation()->get_x())
									+ (m->vertices[i]->get_position()->get_y()
											- player->get_translation()->get_y())
											* (m->vertices[i]->get_position()->get_y()
													- player->get_translation()->get_y())
									+ (m->vertices[i]->get_position()->get_z()
											- player->get_translation()->get_z())
											* (m->vertices[i]->get_position()->get_z()
													- player->get_translation()->get_z()));
			player->set_scale(50 / distance, 50 / distance, 50 / distance);
			matrix4* move = this->player->get_projected_transformation();
			vector4* point = new vector4(m->vertices[j]->get_position());
			point->multiply_first(move);
			if (point->get_x() >= 0 && point->get_x() < 800
					&& point->get_y() >= 0 && point->get_y() < 600) {
				vector2* origin = new vector2((float) 0, (float) 0);
				float p_x = point->get_x();
				float p_y = point->get_y();
				vector2* point = new vector2(p_x, p_y);
				color* white = new color(1, 1, 1, 1);
				rast->draw_line(this->frame, origin, point, white);
				delete origin;
				delete point;
				delete white;
			}
			delete move;
			delete point;
		}
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

