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
	this->min_z = 0;
	this->max_x = this->render_width;
	this->max_y = this->render_height;
	this->max_z = 100;
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
	this->fov = 70;
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
		rotate_y((float) 10);
		break;
	case 108: //l
		rotate_y((float) -10);
		break;
	case 107: //k
		rotate_x((float) 10);
		break;
	case 105: //i
		rotate_x((float) -10);
		break;
	case 97: //a
		move(get_left(), (float) 10);
		break;
	case 100: //d
		move(get_right(), (float) 10);
		break;
	case 115: //s
		move(get_forward(), (float) -10);
		break;
	case 119: //w
		move(get_forward(), (float) 10);
		break;
	default:
		break;
	}
}

camera::~camera() {
	this->cleanup();
}

