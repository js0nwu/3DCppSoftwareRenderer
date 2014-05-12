#include "span.h"

span::span(color a, int x_1, color b, int x_2) {
	this->a_color = a;
	this->b_color = b;
	this->x_1 = x_1;
	this->x_2 = x_2;
}

int span::get_x_1() {
	return this->x_1;
}

int span::get_x_2() {
	return this->x_2;
}

color* span::get_a_color() {
	return &this->a_color;
}

color* span::get_b_color() {
	return &this->b_color;
}

void span::set_x_1(int i) {
	this->x_1 = i;
}

void span::set_x_2(int i) {
	this->x_2 = i;
}

void span::set_a_color(color *c) {
	this->a_color = *c;
}

void span::set_b_color(color* c) {
	this->b_color = *c;
}

span::~span() {

}

