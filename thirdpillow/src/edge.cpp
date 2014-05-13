/*
 * edge.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "edge.h"

edge::edge(vector2 a, color a_color, vector2 b, color b_color) {
	
	if (a.get_y() > b.get_y()) {
		this->a = b;
		this->a_color = b_color;
		this->b = a;
		this->b_color = a_color;
	}
	else {
		this->a = a;
		this->b = b;
		this->a_color = a_color;
		this->b_color = b_color;
	}
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

void edge::print() {
	printf("a (%f, %f) color (%f, %f, %f, %f) b(%f, %f) color (%f, %f, %f, %f)\n", this->a.get_x(), this->b.get_y(), this->a_color.get_r(), this->a_color.get_g(), this->a_color.get_b(), this->a_color.get_a(), this->b.get_x(), this->b.get_y(), this->b_color.get_r(), this->b_color.get_g(), this->b_color.get_b(), this->b_color.get_a());
}

edge::~edge() {
	// TODO Auto-generated destructor stub
}

