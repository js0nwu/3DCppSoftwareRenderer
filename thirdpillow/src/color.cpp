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
    this->a = 255;
}

color::color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

unsigned char color::get_r() {
    return this->r;
}

unsigned char color::get_g() {
    return this->g;
}

unsigned char color::get_b() {
    return this->b;
}

unsigned char color::get_a() {
    return this->a;
}

void color::set_r(unsigned char r) {
    this->r = r;
}

void color::set_g(unsigned char g) {
    this->g = g;
}

void color::set_b(unsigned char b) {
    this->b = b;
}

void color::set_a(unsigned char a) {
    this->a = a;
}

void color::add(color c) {
    this->r += c.get_r();
    this->g += c.get_g();
    this->b += c.get_b();
    this->a += c.get_a();
}

void color::subtract(color c) {
    this->r -= c.get_r();
    this->g -= c.get_g();
    this->b -= c.get_b();
    this->a -= c.get_a();
}

void color::multiply(unsigned char f) {
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

