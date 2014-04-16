/*
 * transform.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "transform.h"

matrix4* transform::get_projected_transformation(float fov, float width, float height, float z_near, float z_far) {
	matrix4* m_transformation = this->get_transformation();
	matrix4* m_projection = new matrix4();
	m_projection->initialize_projection(fov, width, height, z_near, z_far);
	m_projection->multiply(m_transformation);
	delete m_transformation;
	return m_projection;
}

matrix4* transform::get_transformation() {
	matrix4* m_translation = new matrix4();
	m_translation->initialize_translation(translation.get_x(),
			translation.get_y(), translation.get_z());
	matrix4* m_rotation = new matrix4();
	m_rotation->initialize_rotation(rotation.get_x(), rotation.get_y(),
			rotation.get_z());
	matrix4* m_scale = new matrix4();
	m_scale->initialize_scale(scale.get_x(), scale.get_y(), scale.get_z());
	m_rotation->multiply(m_scale);
	m_translation->multiply(m_rotation);

	matrix4* product = m_translation;
	delete m_rotation;
	delete m_scale;
	return product;
}

void transform::set_scale(vector3* s) {
	this->scale = *s;
}

void transform::set_scale(float x, float y, float z) {
	vector3* scale = new vector3(x, y, z);
	this->scale = *scale;
}

vector3* transform::get_scale() {
	return &this->scale;
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

void transform::rotate_degree_xy(float degrees) {
	this->rotation.rotate_degree_xy(degrees);
}

void transform::rotate_degree_yz(float degrees) {
	this->rotation.rotate_degree_yz(degrees);
}

void transform::rotate_degree_xz(float degrees) {
	this->rotation.rotate_degree_xz(degrees);
}

void transform::translate(vector3* delta) {
	this->translation.set_x(this->translation.get_x() + delta->get_x());
	this->translation.set_y(this->translation.get_y() + delta->get_y());
	this->translation.set_z(this->translation.get_z() + delta->get_z());
	this->translation.print();
}

transform::transform(vector3 translation, vector3 rotation, vector3 scale) {
	this->translation = translation;
	this->rotation = rotation;
	this->scale = scale;
}

transform::transform() {
	// TODO Auto-generated constructor stub
	vector3* translation = new vector3();
	vector3* rotation = new vector3();
	vector3* scale = new vector3(1, 1, 1);
	this->translation = *translation;
	this->rotation = *rotation;
	this->scale = *scale;
}

transform::~transform() {
	// TODO Auto-generated destructor stub
}

