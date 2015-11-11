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

void thing::set_texture(image* i) {
    this->texture = i;
}

image* thing::get_texture() {
    return this->texture;
}

thing::thing() {
    transform* t = new transform();
    this->t = *t;
}

thing::~thing() {
    // TODO Auto-generated destructor stub
}

