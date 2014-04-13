/*
 * camera.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "camera.h"

void camera::rotate_degree_xy(float degrees) {
	this->rotation.rotate_degree_xy(degrees);
}

void camera::rotate_degree_yz(float degrees) {
	this->rotation.rotate_degree_yz(degrees);
}

void camera::rotate_degree_xz(float degrees) {
	this->rotation.rotate_degree_xz(degrees);
}

void camera::set_position(vector3* p) {
	this->position = *p;
}

vector3* camera::get_position() {
	return &this->position;
}

void camera::translate(vector3* delta) {
	printf("old position: %f %f %f\n", this->position.get_x(),
			this->position.get_y(), this->position.get_z());
	this->position.set_x(this->position.get_x() + delta->get_x());
	this->position.set_y(this->position.get_y() + delta->get_y());
	this->position.set_z(this->position.get_z() + delta->get_z());
	printf("new position: %f %f %f\n", this->position.get_x(),
			this->position.get_y(), this->position.get_z());
}

int camera::get_index_3d(int x, int y, int z, int wide, int thick) {
	return ((y * wide + x) * thick) + z;
}

void camera::render_mesh(mesh* m) {

}

void camera::render(world* scene) {
	for (int i = 0; i < render_width * render_height * 3; i++) {
		this->frame[i] = 0.5;
	}
}

void camera::activate() {
	this->set_active(true);
}

void camera::deactivate() {
	this->set_active(false);
}

void camera::set_active(bool state) {
	this->active = state;
}

bool camera::is_active() {
	return this->active;
}

float* camera::get_frame() {
	return this->frame;
}

void camera::initialize() {
	printf("initializing camera\n");
	int size = this->render_width * this->render_height * 3;
	this->frame = (float*) malloc(size * sizeof(float));
	this->min_x = 0;
	this->min_y = 0;
	this->min_z = 0;
	this->max_x = this->render_width;
	this->max_y = this->render_height;
	this->max_z = 100;
	this->activate();
}

void camera::cleanup() {
	printf("cleaning up camera");
	free(this->frame);
}

camera::camera(int render_width, int render_height) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->initialize();
	vector3* position = new vector3(5, -5, 8);
	vector3* rotation = new vector3(0, 0, 0);
	rotation->lookat(new vector3(3, 4, 0));
	rotation->normalize();
	this->position = *position;
	this->rotation = *rotation;
}

camera::camera(int render_width, int render_height, vector3 position,
		vector3 rotation) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->initialize();
	this->position = position;
	this->rotation = rotation;
}

camera::~camera() {
	this->cleanup();
}

