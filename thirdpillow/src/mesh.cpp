/*
 * mesh.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "mesh.h"

transform* mesh::get_transform() {
	return &this->m_transform;
}

mesh::mesh() {
	// TODO Auto-generated constructor stub
	transform* t= new transform();
	this->m_transform = *t;
}

mesh::~mesh() {
	// TODO Auto-generated destructor stub
}

