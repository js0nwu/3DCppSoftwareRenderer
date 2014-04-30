/*
 * rasterizer.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "rasterizer.h"

rasterizer::rasterizer() {

}

void rasterizer::draw_line(screen* s, vector2* a, vector2* b, color* c) {
	int w = (int) (b->get_x() - a->get_x());
	int h = (int) (b->get_y() - a->get_y());
	float m = h / (float) w;
	float j = a->get_y();
	for (int i = a->get_x(); i < b->get_x(); i++) {
		s->set_pixel(i, j, c);
		j += m;
	}
}

rasterizer::~rasterizer() {
}

