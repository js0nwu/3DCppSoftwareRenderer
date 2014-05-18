/*
 * engine.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: jwpilly
 */

#include "engine.h"

camera* cam;

world* engine::get_scene() {
	return &this->scene;
}

void engine::cleanup() {
	printf("cleaning up\n");
}

float engine::RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

void engine::initialize() {
	printf("engine initializing\n");
	color* default_color = new color(1, 1, 1, 1); //white
	rast = new rasterizer(default_color);
	player = new transform();
	mesh* m = new mesh();
	cam = new camera(this->frame->get_width(), this->frame->get_height());
	transform::set_camera(cam);
	vector3* start = new vector3(-100, 10, -1);
	cam->set_position(start);
	transform::set_projection((float)70, (float) this->frame->get_width(), this->frame->get_height(), (float) 0.1, (float)1000);
	vector3 tri_v[3];
	for (int i = 0; i < 3; i++) {
		vector3* vertexp = new vector3(RandomFloat(-25, 25), RandomFloat(-25, 25),
			RandomFloat(-25, 25));
		tri_v[i] = *vertexp;
	}
	triangle* tri = new triangle(&tri_v[0]);
	m->faces.push_back(tri);
	thing* t = new thing();
	t->set_mesh(m);
	t->t.set_scale(1, 1, 1);
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
	this->frame->cls();

	vector<vector2*> points;
	for (int i = 0; i < this->scene.things.size(); i++) {
		thing* t = this->scene.things[i];
		mesh* m = t->get_mesh();
		vector3* test_r = t->t.get_rotation();
		t->t.set_rotation(test_r->get_x() + 0.5, test_r->get_y() + 0.5, test_r->get_z() + 0.5);
		vector3* delta = new vector3(0.01, 0.01, 0.01);
		t->t.translate(delta);
		delete delta;
		color* red = new color(1, 0, 0, 1);
		color* green = new color(0, 1, 0, 1);
		color* blue = new color(0, 0, 1, 1);
		for (int j = 0; j < m->faces.size(); j++) {
			for (int k = 0; k < 3; k++) {
				vector4* point = new vector4(m->faces[j]->get_vertices()[k].get_position());
				matrix4* move = t->t.get_projected_transformation();
				point->multiply_first(move);
				float d = point->get_z();
				//vector4 normalization
				point->set_x(point->get_x() / point->get_w());
				point->set_y(point->get_y() / point->get_w());
				point->set_z(point->get_z() / point->get_w());
				if (d > transform::get_camera()->get_z_near()) {
					point->set_x(point->get_x() / point->get_z());
					point->set_y(point->get_y() / point->get_z());
					float x_offset = (float) this->frame->get_width() / (float)2;
					float y_offset = (float) this->frame->get_height() / (float)2;
					float scale = 400;
					float p_x = x_offset + scale * point->get_x() / (point->get_z());
					float p_y = y_offset + scale * point->get_y() / (point->get_z());
					vector2* n_point = new vector2(p_x, p_y);
					points.push_back(n_point);
				}
				delete point;
				delete move;
			}
		}
		if (points.size() == 3) {
			rast->draw_triangle_wire_color(this->frame, points[0], red, points[1], green, points[2], blue);
			rast->draw_triangle_fill_color(this->frame, points[0], red, points[1], green, points[2], blue);
		}
		points.clear();
		delete red;
		delete green;
		delete blue;
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

