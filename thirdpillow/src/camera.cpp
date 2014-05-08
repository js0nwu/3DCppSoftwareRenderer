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

vector3* camera::get_position() {
	return &this->position;
}

vector3* camera::get_forward() {
	return &this->forward;
}

vector3* camera::get_up() {
	return &this->up;
}

void camera::initialize() {
	printf("initializing camera\n");
	this->min_x = 0;
	this->min_y = 0;
	this->max_x = this->render_width;
	this->max_y = this->render_height;
	vector3* up = new vector3(0, 1, 0);
	up->normalize();
	this->y_axis = *up;
}

void camera::cleanup() {
	printf("cleaning up camera");
}

camera::camera(int render_width, int render_height) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->initialize();
	//test projection settings
	this->fov = 70;
	this->z_near = (float) 0.1;
	this->z_far = (float)1000;
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
	this->fov = 70;
	this->z_near = (float) 0.1;
	this->z_far = (float)1000;
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
	vector3 h_axis = y_axis;
	h_axis.cross_product(&this->forward);
	h_axis.normalize();
	forward.rotate(degree, &h_axis);
	forward.normalize();
	up = forward;
	up.cross_product(&h_axis);
	up.normalize();
}
void camera::rotate_y(float degree) {
	vector3 h_axis = y_axis;
	h_axis.cross_product(&this->forward);
	h_axis.normalize();
	forward.rotate(degree, &y_axis);
	forward.normalize();
	up = forward;
	up.cross_product(&h_axis);
	up.normalize();
}

void camera::move(vector3* direction, float amount) {
	vector3* delta = direction->clone();
	delta->multiply(amount);
	this->position.add(delta);
	delete delta;
}

void camera::input(int keycode) {
	switch (keycode) {
	case 106: //j
		rotate_y((float)10);
		break;
	case 108: //l
		rotate_y((float)-10);
		break;
	case 107: //k
		rotate_x((float)10);
		break;
	case 105: //i
		rotate_x((float)-10);
		break;
	case 97: //a
		move(get_left(), (float)-10);
		break;
	case 100: //d
		move(get_right(), (float)-10);
		break;
	case 115: //s
		move(get_forward(), (float)-10);
		break;
	case 119: //w
		move(get_forward(), (float)10);
		break;
	case 113: //q
		move(get_up(), (float)10);
		break;
	case 101: //e
		move(get_up(), (float)-10);
		break;
	default:
		break;
	}
}

float camera::get_fov() {
	return this->fov;
}

void camera::set_fov(float f) {
	this->fov = f;
}

int camera::get_min_x() {
	return this->min_x;
}

void camera::set_min_x(int i) {
	this->min_x = i;
}

int camera::get_max_x() {
	return this->max_x;
}

void camera::set_max_x(int i) {
	this->max_x = i;
}

int camera::get_min_y() {
	return this->min_y;
}

void camera::set_min_y(int i) {
	this->min_y = i;
}

int camera::get_max_y() {
	return this->max_y;
}

void camera::set_max_y(int i) {
	this->max_y = i;
}

float camera::get_z_near() {
	return this->z_near;
}

void camera::set_z_near(float f) {
	this->z_near = f;
}

float camera::get_z_far() {
	return this->z_far;
}

void camera::set_z_far(float f) {
	this->z_far = f;
}

int camera::get_render_width() {
	return this->render_width;
}

void camera::set_render_width(int i) {
	this->render_width = i;
}

int camera::get_render_height() {
	return this->render_height;
}

void camera::set_render_height(int i) {
	this->render_height = i;
}

camera::~camera() {
	this->cleanup();
}

