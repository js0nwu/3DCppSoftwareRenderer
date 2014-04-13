/*
 * transform.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "transform.h"

void transform::set_translation(vector3* t) {
	this->translation = *t->clone();
}

void transform::set_translation(float x, float y, float z) {
	vector3* translation = new vector3(x, y, z);
	this->translation = *translation;
}

vector3* transform::get_translation() {
	return &this->translation;
}

transform::transform(vector3 translation) {
	this->translation = *translation.clone();
}

transform::transform() {
	// TODO Auto-generated constructor stub
	vector3* translation = new vector3();
	this->translation = *translation;
}

transform::~transform() {
	// TODO Auto-generated destructor stub
}

