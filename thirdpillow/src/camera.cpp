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
	this->rotation.normalize();
	//this can be optimized - later
	vector3* w = this->rotation.clone();
	w->negative();
	vector3* up = new vector3(0, 0, 1);
	vector3* u = up->clone();
	u->cross_product(w);
	u->normalize();
	vector3* v = w->clone();
	v->cross_product(u);
	v->normalize();
	matrix4* m_rotation = new matrix4();
	m_rotation->initialize_identity();
	m_rotation->set_at(0, 0, u->get_x());
	m_rotation->set_at(1, 0, u->get_y());
	m_rotation->set_at(2, 0, u->get_z());
	m_rotation->set_at(0, 1, v->get_x());
	m_rotation->set_at(1, 1, v->get_y());
	m_rotation->set_at(2, 1, v->get_z());
	m_rotation->set_at(0, 2, w->get_x());
	m_rotation->set_at(1, 2, w->get_y());
	m_rotation->set_at(2, 2, w->get_z());
	matrix4* translation = new matrix4();
	translation->initialize_identity();
	translation->set_at(3, 0, -this->position.get_x());
	translation->set_at(3, 1, -this->position.get_y());
	translation->set_at(3, 2, -this->position.get_z());
	matrix4* view = m_rotation->clone();
	view->multiply(translation);
	for (int i = 0; i < m->vertices.size(); i++) {
		vector3* local = m->vertices[i]->clone();
		local->transform(view);
		//printf("local %f %f %f\n", local->get_x(), local->get_y(), local->get_z());
		if ((int) local->get_x() >= this->min_x
				&& (int) local->get_x() < this->max_x
				&& (int) local->get_z() >= this->min_z
				&& (int) local->get_z() < this->max_z) {
			//printf("view space: %d, %d\n", (int)local->get_x(), (int)local->get_z());
			int pixel_index = camera::get_index_3d((int) local->get_x(),
					(int) local->get_z(), 0, render_width, 3);
			//printf("pixel index is %d\n", pixel_index); //why does this return negative numbers i have no idea
			this->frame[pixel_index] = 1;
			this->frame[pixel_index + 1] = 1;
			this->frame[pixel_index + 2] = 1;
		}
	}
}

void camera::render(world* scene) {
	//printf("size of things %d\n", scene->things.size());
	for (int i = 0; i < scene->things.size(); i++) {
		this->render_mesh(scene->things[i]->get_mesh());
	}
	/*
	 for (int i = 0; i < render_width*render_height*3; i++) {
	 this->frame[i] = 0.5;
	 }
	 */
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
	vector3* position = new vector3(10, 10, 10);
	vector3* rotation = new vector3(1, 0, 0);
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

