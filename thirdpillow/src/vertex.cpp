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

vertex::vertex() {
    // TODO Auto-generated constructor stub

}

vertex::vertex(vector3 position) {
    this->position = position;
}

vertex::~vertex() {
    // TODO Auto-generated destructor stub
}

