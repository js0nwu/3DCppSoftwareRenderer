/*
 * vector3.cpp
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#include "vector3.h"

void vector3::transform(matrix4* v) {
	float x_prime = v->get_at(0, 0) * this->x + v->get_at(0, 1) * this->y
			+ v->get_at(0, 2) * this->z + v->get_at(0, 3);
	float y_prime = v->get_at(1, 0) * this->x + v->get_at(1, 1) * this->y
			+ v->get_at(1, 2) * this->z + v->get_at(1, 3);
	float z_prime = v->get_at(2, 0) * this->x + v->get_at(2, 1) * this->y
			+ v->get_at(2, 2) * this->z + v->get_at(2, 3);
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
}
vector3* vector3::clone() {
	vector3* clone = new vector3(this->x, this->y, this->z);
	return clone;
}

float vector3::get_x() {
	return this->x;
}

float vector3::get_y() {
	return this->y;
}

float vector3::get_z() {
	return this->z;
}
void vector3::set_x(float x) {
	this->x = x;
}

void vector3::set_y(float y) {
	this->y = y;
}

void vector3::set_z(float z) {
	this->z = z;
}

float vector3::magnitude() {
	float magnitude = sqrt(
			(this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	return magnitude;
}

float vector3::distance_from(vector3* v) {
	float x_2 = v->get_x();
	float y_2 = v->get_y();
	float z_2 = v->get_z();
	float distance = sqrt(
			(x_2 - v->get_x()) * (x_2 - v->get_x())
					+ (y_2 - v->get_y()) * (y_2 - v->get_y())
					+ (z_2 - v->get_z()) * (z_2 - v->get_z()));
	return distance;
}

void vector3::normalize() {
	float magnitude = this->magnitude();
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

void vector3::negative() {
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
}

float vector3::dot_product(vector3* v) {
	return (this->x * v->get_x()) + (this->y * v->get_y())
			+ (this->z * v->get_z());
}

void vector3::cross_product(vector3* v) {
	float x = this->x;
	float y = this->y;
	float z = this->z;
	this->x = y * v->get_z() - z * v->get_y();
	this->y = z * v->get_x() - x * v->get_z();
	this->z = x * v->get_y() - y * v->get_x();
}

float vector3::angle_between(vector3* v) {
	float total_magnitude = this->magnitude() + v->magnitude();
	float dot_product = this->dot_product(v);
	float angle_radian = acos(dot_product / total_magnitude);
	float angle = ((float) 180 * angle_radian) / (float) 3.14;
	return angle;
}

void vector3::rotate_degree_xy(float degrees) {
	float radians = (degrees * (float) 3.14) / (float) 180;
	float x_prime = (this->x * cos(radians)) + (this->y * -sin(radians))
			+ (this->z * 0);
	float y_prime = (this->x * sin(radians)) + (this->y * cos(radians))
			+ (this->z * 0);
	float z_prime = (this->x * 0) + (this->y * 0) + (this->z * 1);
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
}

void vector3::rotate_degree_yz(float degrees) {
	float radians = (degrees * (float) 3.14) / (float) 180;
	float x_prime = (this->x * 1) + (this->y * 0) + (this->z * 0);
	float y_prime = (this->x * 0) + (this->y * 1) + (this->z * 0);
	float z_prime = (this->x * -sin(radians)) + (this->y * 0)
			+ (this->z * cos(radians));
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
}

void vector3::rotate_degree_xz(float degrees) {
	float radians = (degrees * (float) 3.14) / (float) 180;
	float x_prime = (this->x * cos(radians)) + (this->y * 0)
			+ (this->z * sin(radians));
	float y_prime = (this->x * 0) + (this->y * 1) + (this->z * 0);
	float z_prime = (this->x * -sin(radians)) + (this->y * 0)
			+ (this->z * cos(radians));
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
}

void vector3::add(float s) {
	this->x = this->x + s;
	this->y = this->y + s;
	this->z = this->z + s;
}

void vector3::add(vector3* v) {
	this->x = this->x + v->get_x();
	this->y = this->y + v->get_y();
	this->z = this->z + v->get_z();
}

void vector3::subtract(float s) {
	this->x = this->x - s;
	this->y = this->y - s;
	this->z = this->z - s;
}

void vector3::subtract(vector3* v) {
	this->x = this->x - v->get_x();
	this->y = this->y - v->get_y();
	this->z = this->z - v->get_z();
}

void vector3::multiply(float s) {
	this->x = this->x * s;
	this->y = this->y * s;
	this->z = this->z * s;
}

void vector3::multiply(vector3* v) {
	this->x = this->x * v->get_x();
	this->y = this->y * v->get_y();
	this->z = this->z * v->get_z();
}

void vector3::divide(float s) {
	this->x = this->x / s;
	this->y = this->y / s;
	this->z = this->z / s;
}

void vector3::divide(vector3* v) {
	this->x = this->x / v->get_x();
	this->y = this->y / v->get_y();
	this->z = this->z / v->get_z();
}

void vector3::scale(vector3* f) {
	float x_prime = this->x * f->get_x();
	float y_prime = this->y * f->get_y();
	float z_prime = this->z * f->get_z();
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
}

vector3::vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

vector3::vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

vector3::~vector3() {

}

