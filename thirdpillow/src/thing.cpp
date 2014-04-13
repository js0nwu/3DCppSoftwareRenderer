/*
 * thing.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "thing.h"

void thing::set_mesh(mesh* m) {
	this->geometry = m;
}

mesh* thing::get_mesh() {
	return this->geometry;
}

thing::thing() {
	// TODO Auto-generated constructor stub

}

thing::~thing() {
	// TODO Auto-generated destructor stub
}

