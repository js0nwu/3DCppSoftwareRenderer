/*
 * thing.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "thing.h"

void thing::set_mesh(mesh m) {
    geometry = m;
}

mesh thing::get_mesh() {
    return geometry;
}

void thing::set_texture(image i) {
    texture = i;
}

image thing::get_texture() {
    return texture;
}

thing::thing() {

}

thing::~thing() {
    // TODO Auto-generated destructor stub
}

