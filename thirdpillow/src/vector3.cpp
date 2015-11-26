/*
 * vector3.cpp
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#include "vector3.h"

void vector3::print() {
    printf("vector3: %f %f %f\n", this->x, this->y, this->z);
}

void vector3::rotate(float degree, vector3 axis) {
    float radians = (degree * (float) 3.14) / (float)180;
    float sin_half = sin(radians / 2);
    float cos_half = cos(radians / 2);
    float r_x = axis.get_x() * sin_half;
    float r_y = axis.get_y() * sin_half;
    float r_z = axis.get_z() * sin_half;
    float r_w = cos_half;
    quaternion rotation(r_x, r_y, r_z, r_w);
    quaternion c = rotation;
    c.conjugate();
    quaternion w = rotation;
    w.multiply(this->x, this->y, this->z);
    w.multiply(c);
    this->x = w.get_x();
    this->y = w.get_y();
    this->z = w.get_z();
}

bool vector3::is_zero() {
    return (this->x == 0 && this->y == 0 && this->z == 0);
}

void vector3::lookat(vector3 v) {
    vector3 r(v.get_x() - this->x, v.get_y() - this->y,
              v.get_z() - this->z);
    r.normalize();
    this->x = r.get_x();
    this->y = r.get_y();
    this->z = r.get_z();
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

float vector3::distance_from(vector3 v) {
    float x_2 = v.get_x();
    float y_2 = v.get_y();
    float z_2 = v.get_z();
    float distance = sqrt(
                         (x_2 - v.get_x()) * (x_2 - v.get_x())
                         + (y_2 - v.get_y()) * (y_2 - v.get_y())
                         + (z_2 - v.get_z()) * (z_2 - v.get_z()));
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

float vector3::dot_product(vector3 v) {
    return (this->x * v.get_x()) + (this->y * v.get_y())
           + (this->z * v.get_z());
}

void vector3::cross_product(vector3 v) {
    float x = this->x;
    float y = this->y;
    float z = this->z;
    this->x = y * v.get_z() - z * v.get_y();
    this->y = z * v.get_x() - x * v.get_z();
    this->z = x * v.get_y() - y * v.get_x();
}

float vector3::angle_between(vector3 v) {
    float total_magnitude = this->magnitude() * v.magnitude();
    float dot_product = this->dot_product(v);
    float angle_radian = acos(dot_product / total_magnitude);
    float angle = ((float)180 * angle_radian) / (float) 3.14;
    return angle;
}

void vector3::add(float s) {
    this->x = this->x + s;
    this->y = this->y + s;
    this->z = this->z + s;
}

void vector3::add(vector3 v) {
    this->x = this->x + v.get_x();
    this->y = this->y + v.get_y();
    this->z = this->z + v.get_z();
}

void vector3::subtract(float s) {
    this->x = this->x - s;
    this->y = this->y - s;
    this->z = this->z - s;
}

void vector3::subtract(vector3 v) {
    this->x = this->x - v.get_x();
    this->y = this->y - v.get_y();
    this->z = this->z - v.get_z();
}

void vector3::multiply(float s) {
    this->x = this->x * s;
    this->y = this->y * s;
    this->z = this->z * s;
}

void vector3::multiply(vector3 v) {
    this->x = this->x * v.get_x();
    this->y = this->y * v.get_y();
    this->z = this->z * v.get_z();
}

void vector3::divide(float s) {
    this->x = this->x / s;
    this->y = this->y / s;
    this->z = this->z / s;
}

void vector3::divide(vector3 v) {
    this->x = this->x / v.get_x();
    this->y = this->y / v.get_y();
    this->z = this->z / v.get_z();
}

void vector3::scale(vector3 f) {
    float x_prime = this->x * f.get_x();
    float y_prime = this->y * f.get_y();
    float z_prime = this->z * f.get_z();
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

