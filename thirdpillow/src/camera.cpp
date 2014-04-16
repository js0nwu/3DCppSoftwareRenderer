/*
 * camera.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "camera.h"

void camera::clear() {
	for (int i = 0; i < this->render_width * this->render_height * 3; i++) {
		this->frame[i] = 0;
	}
}

void camera::set_rotation(vector3* r) {
	this->m_transform.set_rotation(r);
}

vector3* camera::get_rotation() {
	return this->m_transform.get_rotation();
}

void camera::rotate_degree_xy(float degrees) {
	this->m_transform.rotate_degree_xy(degrees);
}

void camera::rotate_degree_yz(float degrees) {
	this->m_transform.rotate_degree_yz(degrees);
}

void camera::rotate_degree_xz(float degrees) {
	this->m_transform.rotate_degree_xz(degrees);
}

void camera::set_position(vector3* p) {
	this->m_transform.set_translation(p);
}

vector3* camera::get_position() {
	return this->m_transform.get_translation();
}

void camera::translate(vector3* delta) {
	this->m_transform.translate(delta);
}

int camera::get_index_3d(int x, int y, int z, int wide, int thick) {
	return ((y * wide + x) * thick) + z;
}

void camera::render_mesh(mesh* m) {
	for (int i = 0; i < m->vertices.size(); i++) {
		vector3 pos = *this->get_position();
		vector3 rot = *this->get_rotation();
		vector3 scale = *this->m_transform.get_scale();
		transform* t = new transform(pos, rot, scale);
		vector4* p = new vector4(m->vertices[i]->get_position());
		matrix4* m_transformation = t->get_projected_transformation(this->fov,
				(float) this->render_width, (float) this->render_height,
				this->z_near, this->z_far);
		p->multiply_first(m_transformation);
		if ((int) p->get_x() >= this->min_x && (int) p->get_x() < this->max_x
				&& (int) p->get_y() >= this->min_y
				&& (int) p->get_y() < this->max_y) {
			int pixel_index = camera::get_index_3d((int) p->get_x(),
					(int) p->get_y(), 0, render_width, 3);
			this->frame[pixel_index] = 1;
			this->frame[pixel_index + 1] = 1;
			this->frame[pixel_index + 2] = 1;
		}
		delete m_transformation;
		delete p;
		delete t;
	}
}

void camera::render(world* scene) {
	this->clear();
	for (int i = 0; i < scene->things.size(); i++) {
		this->render_mesh(scene->things[i]->get_mesh());
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
	vector3* scale = new vector3(1, 1, 1);
	rotation->lookat(new vector3(3, 4, 0));
	rotation->normalize();
	transform* t = new transform(*position, *rotation, *scale);
	this->m_transform = *t;

	//test projection settings
	this->fov = 88;
	this->z_near = (float) 0.1;
	this->z_far = (float) 1000;
}

camera::camera(int render_width, int render_height, vector3 position,
		vector3 rotation, vector3 scale) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->initialize();
	transform* t = new transform(position, rotation, scale);
	this->m_transform = *t;

	//test projection settings
	this->fov = 88;
	this->z_near = (float) 0.1;
	this->z_far = (float) 1000;
}

camera::~camera() {
	this->cleanup();
}

