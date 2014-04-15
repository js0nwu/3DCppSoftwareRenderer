/*
 * transform.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "transform.h"

matrix4* transform::get_transformation() {
	matrix4* m_translation = new matrix4();
	m_translation->initialize_translation(translation.get_x(),
			translation.get_y(), translation.get_z());
	matrix4* m_rotation = new matrix4();
	m_rotation->initialize_rotation(rotation.get_x(), rotation.get_y(),
			rotation.get_z());

	m_translation->multiply(m_rotation);

	matrix4* product = m_translation->clone();
	delete m_translation;
	delete m_rotation;
	return product;
}

void transform::set_translation(vector3* t) {
	this->translation = *t; //do you need clone?
}

void transform::set_translation(float x, float y, float z) {
	vector3* translation = new vector3(x, y, z);
	this->translation = *translation;
}

vector3* transform::get_translation() {
	return &this->translation;
}

void transform::set_rotation(vector3* r) {
	this->rotation = *r; //do you need clone?
}

void transform::set_rotation(float x, float y, float z) {
	vector3* rotation = new vector3(x, y, z);
	this->rotation = *rotation;
}

vector3* transform::get_rotation() {
	return &this->rotation;
}

transform::transform(vector3 translation, vector3 rotation) {
	this->translation = translation;
	this->rotation = rotation;
}

transform::transform() {
	// TODO Auto-generated constructor stub
	vector3* translation = new vector3();
	vector3* rotation = new vector3();
	this->translation = *translation;
	this->rotation = *rotation;
}

transform::~transform() {
	// TODO Auto-generated destructor stub
}

