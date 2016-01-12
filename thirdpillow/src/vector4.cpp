/*
 * vector4.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "vector4.h"

void vector4::print() {
    printf("vector4: %f %f %f %f\n", x, y, z, w);
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
    return x;
}

float vector4::get_y() {
    return y;
}

float vector4::get_z() {
    return z;
}

float vector4::get_w() {
    return w;
}

void vector4::multiply_first(matrix4 m) {
    //rewrite this with a loop ... later
    float x_prime = m.get_at(0, 0) * x + m.get_at(0, 1) * y + m.get_at(0, 2) * z + m.get_at(0, 3) * w;
    float y_prime = m.get_at(1, 0) * x + m.get_at(1, 1) * y + m.get_at(1, 2) * z + m.get_at(1, 3) * w;
    float z_prime = m.get_at(2, 0) * x + m.get_at(2, 1) * y + m.get_at(2, 2) * z + m.get_at(2, 3) * w;
    float w_prime = m.get_at(3, 0) * x + m.get_at(3, 1) * y + m.get_at(3, 2) * z + m.get_at(3, 3) * w;
    //printf("%f, %f, %f, %f\n", x_prime, y_prime, z_prime, w_prime);
    x = x_prime;
    y = y_prime;
    z = z_prime;
    w = w_prime; //this should always be 1?
}

vector4::vector4() {
    // TODO Auto-generated constructor stub
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

vector4::vector4(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vector4::vector4(vector3 v) {
    x = v.get_x();
    y = v.get_y();
    z = v.get_z();
    w = (float) 1;
}

vector4::~vector4() {
    // TODO Auto-generated destructor stub
}

vector4* vector4::clone() {
    vector4* clone = new vector4(x, y, z, w);
    return clone;
}

