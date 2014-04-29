/*
 * color.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "color.h"

color::color() {
	this->r = 0;
	this->g = 0;
	this->b = 0;
	this->a = 0;
}

color::color(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

float color::get_r() {
	return this->r;
}

float color::get_g() {
	return this->g;
}

float color::get_b() {
	return this->b;
}

float color::get_a() {
	return this->a;
}

void color::set_r(float r) {
	this->r = r;
}

void color::set_g(float g) {
	this->g = g;
}

void color::set_b(float b) {
	this->b = b;
}

void color::set_a(float a) {
	this->a = a;
}

void color::add(color* c) {
	this->r += c->get_r();
	this->g += c->get_g();
	this->b += c->get_b();
	this->a += c->get_a();
}

void color::subtract(color* c) {
	this->r -= c->get_r();
	this->g -= c->get_g();
	this->b -= c->get_b();
	this->a -= c->get_a();
}

void color::multiply(float f) {
	this->r *= f;
	this->g *= f;
	this->b *= f;
	this->a *= f;
}

color* color::clone() {
	color* clone = new color(this->r, this->g, this->b, this->a);
	return clone;
}

color::~color() {

}

