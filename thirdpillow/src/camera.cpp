/*
 * camera.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "camera.h"

void camera::set_position(vector3* p) {
	this->position = *p;
}

matrix4* camera::get_view_projection() {
	vector3* r = new vector3(1, 0, 0);
	vector3* s = new vector3(1, 1, 1);
	transform* t = new transform(this->position, *r, *s);
	matrix4* transformation = t->get_transformation();
	transformation->print();
	matrix4* projection = new matrix4();
	projection->initialize_projection(this->fov, (float) this->render_width,
			(float) this->render_height, this->z_near, this->z_far);
	matrix4* m_camera = new matrix4();
	m_camera->initialize_camera(&this->forward, &this->up);
	matrix4* m_camera_translation = new matrix4();
	m_camera_translation->initialize_translation(-this->position.get_x(), -this->position.get_y(), -this->position.get_z());
	m_camera_translation->multiply(transformation);
	m_camera->multiply(m_camera_translation);
	projection->multiply(m_camera);
	delete transformation;
	delete m_camera;
	delete r;
	delete s;
	delete m_camera_translation;
	return projection;
}

void camera::clear() {
	for (int i = 0; i < this->render_width * this->render_height * 3; i++) {
		this->frame[i] = 0;
	}
}
int camera::get_index_3d(int x, int y, int z, int wide, int thick) {
	return ((y * wide + x) * thick) + z;
}

void camera::render_mesh(mesh* m) {
	for (int i = 0; i < m->vertices.size(); i++) {
		matrix4* m_transformation = this->get_view_projection();
		vector4* p = new vector4(m->vertices[i]->get_position());
		printf("p %f %f %f %f\n", p->get_x(), p->get_y(), p->get_z());
		p->multiply_first(m_transformation);
		printf("p %f %f %f %f\n", p->get_x(), p->get_y(), p->get_z());
		exit(-1);
		if ((int) p->get_x() >= this->min_x && (int) p->get_x() < this->max_x && (int) p->get_y() >= this->min_y && p->get_y() < this->max_y) {
			int pixel_index = camera::get_index_3d((int) p->get_x(), (int) p->get_y(), 0, render_width, 3);
			this->frame[pixel_index] = 1;
			this->frame[pixel_index + 1] = 1;
			this->frame[pixel_index + 2] = 1;
		}
		delete m_transformation;
		delete p;
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
	vector3* up = new vector3(0, 1, 0);
	up->normalize();
	this->y_axis = *up;
}

void camera::cleanup() {
	printf("cleaning up camera");
	free(this->frame);
}

camera::camera(int render_width, int render_height) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->initialize();
	//test projection settings
	this->fov = 88;
	this->z_near = (float) 0.1;
	this->z_far = (float) 1000;
	vector3* forward = new vector3(1, 0, 0);
	this->forward = *forward;
	vector3* up = new vector3(0, 1, 0);
	this->up = *up;
	vector3* pos = new vector3(0, 0, 0);
	this->position = *pos;
}

camera::camera(int render_width, int render_height, vector3 pos,
		vector3 forward, vector3 up) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->initialize();
	this->fov = 88;
	this->z_near = (float) 0.1;
	this->z_far = (float) 1000;
	this->position = pos;
	this->forward = forward;
	this->up = up;
}

vector3* camera::get_left() {
	vector3* left = this->up.clone();
	left->cross_product(&this->forward);
	left->normalize();
	return left;
}

vector3* camera::get_right() {
	vector3* right = this->forward.clone();
	right->cross_product(&this->up);
	right->normalize();
	return right;
}

void camera::rotate_x(float degree) {
	vector3* h_axis = y_axis.clone();
	h_axis->cross_product(&this->forward);
	h_axis->normalize();
	forward.rotate(degree, h_axis);
	forward.normalize();
	up = *forward.clone();
	up.cross_product(h_axis);
	up.normalize();
	delete h_axis;
}
void camera::rotate_y(float degree) {
	vector3* h_axis = y_axis.clone();
	h_axis->cross_product(&this->forward);
	h_axis->normalize();
	forward.rotate(degree, h_axis);
	forward.normalize();
	up = *forward.clone();
	up.cross_product(h_axis);
	up.normalize();
	delete h_axis;
}

void camera::move(vector3* direction, float amount) {
	vector3* delta = direction;
	direction->multiply(amount);
	this->position.add(delta);
}

camera::~camera() {
	this->cleanup();
}

