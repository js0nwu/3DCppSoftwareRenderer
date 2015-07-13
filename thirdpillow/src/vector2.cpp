/*
 * vector2.cpp
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#include "vector2.h"

int vector2::get_index_2d(int x, int y, int wide) {
	return y * wide + x;
}

void vector2::set_x(float x) {
	this->x = x;
}

void vector2::set_y(float y) {
	this->y = y;
}

float vector2::get_x() {
	return this->x;
}

float vector2::get_y() {
	return this->y;
}

float vector2::magnitude() {
	return (float) (sqrt((this->x * this->x) + (this->y * this->y)));
}

float vector2::distance_from(vector2 v) {
	float x_2 = v.get_x();
	float y_2 = v.get_y();
	float distance = (float) (sqrt(
			((x_2 - this->x) * (x_2 - this->x))
					+ ((y_2 - this->y) * (y_2 - this->y))));
	return distance;
}

void vector2::normalize() {
	float magnitude = this->magnitude();
	this->x /= magnitude;
	this->y /= magnitude;
}

void vector2::negative() {
	this->x = -this->x;
	this->y = -this->y;
}

float vector2::dot_product(vector2 v) {
	return (this->x * v.get_x()) + (this->y * v.get_y());
}

void vector2::cross_product(vector2 v) {
	float x = this->x;
	float y = this->y;
	this->x = x * v.get_y();
	this->y = y * v.get_x();
}

float vector2::angle_between(vector2 v) {
	float dot_product = this->dot_product(v);
	float total_magnitude = this->magnitude() + v.magnitude();
	float angle_radian = acos(dot_product / total_magnitude);
	float angle = (angle_radian * (float) 180) / (float) 3.14;
	return angle;
}

void vector2::rotate_degree(float degrees) {
	float radians = (degrees * (float) 3.14) / (float) 180;
	float x_prime = this->x * cos(radians) - this->y * sin(radians);
	float y_prime = this->x * sin(radians) + this->y * cos(radians);
	this->x = x_prime;
	this->y = y_prime;
}

void vector2::add(float s) {
	this->x = this->x + s;
	this->y = this->y + s;
}

void vector2::add(vector2 v) {
	this->x = this->x + v.get_x();
	this->y = this->y + v.get_y();
}

void vector2::subtract(float s) {
	this->x = this->x - s;
	this->y = this->y - s;
}

void vector2::subtract(vector2 v) {
	this->x = this->x - v.get_x();
	this->y = this->y - v.get_y();
}

void vector2::multiply(float s) {
	this->x = this->x * s;
	this->y = this->y * s;
}

void vector2::multiply(vector2 v) {
	this->x = this->x * v.get_x();
	this->y = this->y * v.get_y();
}

void vector2::divide(float s) {
	this->x = this->x / s;
	this->y = this->y / s;
}

void vector2::divide(vector2 v) {
	this->x = this->x / v.get_x();
	this->y = this->y / v.get_y();
}

void vector2::scale(vector2 f) {
	float x_prime = this->x * f.get_x();
	float y_prime = this->y * f.get_y();
	this->x = x_prime;
	this->y = y_prime;
}

vector2* vector2::clone() {
	vector2* clone = new vector2(this->get_x(), this->get_y());
	return clone;
}

vector2::vector2() {
	this->x = 0;
	this->y = 0;
}

vector2::vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

vector2::~vector2() {

}

