/*
 * vector3.cpp
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#include "vector3.h"

void vector3::print() {
    printf("vector3: %f %f %f\n", x, y, z);
}

void vector3::rotate(float radians, vector3 axis) {
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
    w.multiply(x, y, z);
    w.multiply(c);
    x = w.get_x();
    y = w.get_y();
    z = w.get_z();
}

bool vector3::is_zero() {
    return (x == 0 && y == 0 && z == 0);
}

void vector3::lookat(vector3 v) {
    vector3 r(v.get_x() - x, v.get_y() - y,
              v.get_z() - z);
    r.normalize();
    x = r.get_x();
    y = r.get_y();
    z = r.get_z();
}

vector3* vector3::clone() {
    vector3* clone = new vector3(x, y, z);
    return clone;
}

float vector3::get_x() {
    return x;
}

float vector3::get_y() {
    return y;
}

float vector3::get_z() {
    return z;
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
                          (x * x) + (y * y) + (z * z));
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
    float mag = magnitude();
    x /= mag;
    y /= mag;
    z /= mag;
}

void vector3::negative() {
    x = -x;
    y = -y;
    z = -z;
}

float vector3::dot_product(vector3 v) {
    return (x * v.get_x()) + (y * v.get_y())
           + (z * v.get_z());
}

void vector3::cross_product(vector3 v) {
    float x1 = x;
    float y1 = y;
    float z1 = z;
    x = y1 * v.get_z() - z1 * v.get_y();
    y = z1 * v.get_x() - x1 * v.get_z();
    z = x1 * v.get_y() - y1 * v.get_x();
}

float vector3::angle_between(vector3 v) {
    float total_magnitude = magnitude() * v.magnitude();
    float dp = dot_product(v);
    return acos(dp / total_magnitude);
}

void vector3::add(float s) {
    x = x + s;
    y = y + s;
    z = z + s;
}

void vector3::add(vector3 v) {
    x = x + v.get_x();
    y = y + v.get_y();
    z = z + v.get_z();
}

void vector3::subtract(float s) {
    x = x - s;
    y = y - s;
    z = z - s;
}

void vector3::subtract(vector3 v) {
    x = x - v.get_x();
    y = y - v.get_y();
    z = z - v.get_z();
}

void vector3::multiply(float s) {
    x = x * s;
    y = y * s;
    z = z * s;
}

void vector3::multiply(vector3 v) {
    x = x * v.get_x();
    y = y * v.get_y();
    z = z * v.get_z();
}

void vector3::divide(float s) {
    x = x / s;
    y = y / s;
    z = z / s;
}

void vector3::divide(vector3 v) {
    x = x / v.get_x();
    y = y / v.get_y();
    z = z / v.get_z();
}

void vector3::scale(vector3 f) {
    float x_prime = x * f.get_x();
    float y_prime = y * f.get_y();
    float z_prime = z * f.get_z();
    x = x_prime;
    y = y_prime;
    z = z_prime;
}

vector3::vector3() {
    x = 0;
    y = 0;
    z = 0;
}

vector3::vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

vector3::~vector3() {

}

