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
    x = x;
}

void vector2::set_y(float y) {
    y = y;
}

float vector2::get_x() {
    return x;
}

float vector2::get_y() {
    return y;
}

float vector2::magnitude() {
    return (float) (sqrt((x * x) + (y * y)));
}

float vector2::distance_from(vector2 v) {
    float x_2 = v.get_x();
    float y_2 = v.get_y();
    float distance = (float) (sqrt(
            ((x_2 - x) * (x_2 - x))
            + ((y_2 - y) * (y_2 - y))));
    return distance;
}

void vector2::normalize() {
    float mag = magnitude();
    x /= mag;
    y /= mag;
}

void vector2::negative() {
    x = -x;
    y = -y;
}

float vector2::dot_product(vector2 v) {
    return (x * v.get_x()) + (y * v.get_y());
}

void vector2::cross_product(vector2 v) {
    float x2 = x;
    float y2 = y;
    x = x2 * v.get_y();
    y = y2 * v.get_x();
}

float vector2::angle_between(vector2 v) {
    float dp = dot_product(v);
    float total_magnitude = magnitude() + v.magnitude();
    return acos(dp / total_magnitude);
}

void vector2::rotate(float radians) {
    float x_prime = x * cos(radians) - y * sin(radians);
    float y_prime = x * sin(radians) + y * cos(radians);
    x = x_prime;
    y = y_prime;
}

void vector2::add(float s) {
    x = x + s;
    y = y + s;
}

void vector2::add(vector2 v) {
    x = x + v.get_x();
    y = y + v.get_y();
}

void vector2::subtract(float s) {
    x = x - s;
    y = y - s;
}

void vector2::subtract(vector2 v) {
    x = x - v.get_x();
    y = y - v.get_y();
}

void vector2::multiply(float s) {
    x = x * s;
    y = y * s;
}

void vector2::multiply(vector2 v) {
    x = x * v.get_x();
    y = y * v.get_y();
}

void vector2::divide(float s) {
    x = x / s;
    y = y / s;
}

void vector2::divide(vector2 v) {
    x = x / v.get_x();
    y = y / v.get_y();
}

void vector2::scale(vector2 f) {
    float x_prime = x * f.get_x();
    float y_prime = y * f.get_y();
    x = x_prime;
    y = y_prime;
}

vector2* vector2::clone() {
    vector2* clone = new vector2(get_x(), get_y());
    return clone;
}

vector2::vector2() {
    x = 0;
    y = 0;
}

vector2::vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

vector2::~vector2() {

}

