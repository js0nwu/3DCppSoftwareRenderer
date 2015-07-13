/*
 * vector4.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "vector4.h"

void vector4::print() {
	printf("vector4: %f %f %f %f\n", this->x, this->y, this->z, this->w);
}

void vector4::set_x(float x) {
	this->x = x;
}

void vector4::set_y(float y) {
	this->y = y;
}

void vector4::set_z(float z) {
	this->z = z;
}

void vector4::set_w(float w) {
	this->w = w;
}

float vector4::get_x() {
	return this->x;
}

float vector4::get_y() {
	return this->y;
}

float vector4::get_z() {
	return this->z;
}

float vector4::get_w() {
	return this->w;
}

void vector4::multiply_first(matrix4 m) {
	//rewrite this with a loop ... later
	float x_prime = m.get_at(0, 0) * this->x + m.get_at(0, 1) * this->y + m.get_at(0, 2) * this->z + m.get_at(0, 3) * this->w;
	float y_prime = m.get_at(1, 0) * this->x + m.get_at(1, 1) * this->y + m.get_at(1, 2) * this->z + m.get_at(1, 3) * this->w;
	float z_prime = m.get_at(2, 0) * this->x + m.get_at(2, 1) * this->y + m.get_at(2, 2) * this->z + m.get_at(2, 3) * this->w;
	float w_prime = m.get_at(3, 0) * this->x + m.get_at(3, 1) * this->y + m.get_at(3, 2) * this->z + m.get_at(3, 3) * this->w;
	//printf("%f, %f, %f, %f\n", x_prime, y_prime, z_prime, w_prime);
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
	this->w = w_prime; //this should always be 1?
}

vector4::vector4() {
	// TODO Auto-generated constructor stub
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

vector4::vector4(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

vector4::vector4(vector3 v) {
	this->x = v.get_x();
	this->y = v.get_y();
	this->z = v.get_z();
	this->w = (float) 1;
}

vector4::~vector4() {
	// TODO Auto-generated destructor stub
}

vector4* vector4::clone() {
	vector4* clone = new vector4(this->x, this->y, this->z, this->w);
	return clone;
}

