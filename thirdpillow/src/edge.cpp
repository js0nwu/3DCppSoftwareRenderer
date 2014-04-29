/*
 * edge.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "edge.h"

edge::edge(vector2 a, color a_color, vector2 b, color b_color) {
	this->a = a;
	this->b = b;
	this->a_color = a_color;
	this->b_color = b_color;
}

vector2* edge::get_a() {
	return &this->a;
}

vector2* edge::get_b() {
	return &this->b;
}

color* edge::get_a_color() {
	return &this->a_color;
}

color* edge::get_b_color() {
	return &this->b_color;
}

void edge::set_a(vector2* v) {
	this->a = *v;
}

void edge::set_b(vector2* v) {
	this->b = *v;
}

void edge::set_a_color(color* c) {
	this->a_color = *c;
}

void edge::set_b_color(color* c) {
	this->b_color = *c;
}

edge* edge::clone() {
	edge* clone = new edge(this->a, this->a_color, this->b, this->b_color);
	return clone;
}

edge::~edge() {
	// TODO Auto-generated destructor stub
}

