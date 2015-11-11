/*
 * edge.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "edge.h"

edge::edge() {
}

edge::edge(vector2 a, vector2 uv_a, float z_a, vector2 b, vector2 uv_b, float z_b) {

    if (a.get_y() > b.get_y()) {
        this->a = b;
        this->uv_a = uv_b;
        this->b = a;
        this->uv_b = uv_a;
        this->z_b = z_a;
        this->z_a = z_b;
    }
    else {
        this->a = a;
        this->b = b;
        this->uv_a = uv_a;
        this->uv_b = uv_b;
        this->z_a = z_a;
        this->z_b = z_b;
    }
}

float edge::get_z_a() {
    return this->z_a;
}

float edge::get_z_b() {
    return this->z_b;
}

void edge::set_z_a(float z) {
    this->z_a = z;
}

void edge::set_z_b(float z) {
    this->z_b = z;
}

vector2 edge::get_a() {
    return this->a;
}

vector2 edge::get_b() {
    return this->b;
}

vector2 edge::get_uv_a() {
    return this->uv_a;
}

vector2 edge::get_uv_b() {
    return this->uv_b;
}

void edge::set_a(vector2 v) {
    this->a = v;
}

void edge::set_b(vector2 v) {
    this->b = v;
}

void edge::set_uv_a(vector2 v) {
    this->uv_a = v;
}

void edge::set_uv_b(vector2 v) {
    this->uv_b = v;
}

edge* edge::clone() {
    edge* clone = new edge(this->a, this->uv_a, this->z_a, this->b, this->uv_b, this->z_b);
    return clone;
}

void edge::print() {
    printf("a (%f, %f) uv_a (%f, %f) b(%f, %f) uv_b (%f, %f)\n", this->a.get_x(), this->a.get_y(), this->uv_a.get_x(), this->uv_a.get_y(), this->b.get_x(), this->b.get_y(), this->uv_b.get_x(), this->uv_b.get_y());
}

edge::~edge() {
    // TODO Auto-generated destructor stub
}

