/*
 * vertex.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "vertex.h"

void vertex::set_position(vector3* p) {
	this->position.set_x(p->get_x());
	this->position.set_y(p->get_y());
	this->position.set_z(p->get_z());
}

vector3* vertex::get_position() {
	return &this->position;
}

void vertex::set_normal(vector3* p) {
	this->normal.set_x(p->get_x());
	this->normal.set_y(p->get_y());
	this->normal.set_z(p->get_z());
}

vector3* vertex::get_normal() {
	return &this->normal;
}

vector2* vertex::get_uv() {
	return &this->uv;
}

void vertex::set_uv(vector2* p) {
	this->uv.set_x(p->get_x());
	this->uv.set_y(p->get_y());
}

vertex::vertex() {
	// TODO Auto-generated constructor stub

}

vertex::vertex(vector3 position) {
	this->position = position;
}

vertex::~vertex() {
	// TODO Auto-generated destructor stub
}

