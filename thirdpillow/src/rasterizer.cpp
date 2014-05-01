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

void rasterizer::draw_line(screen* s, vector2* a, color* a_color, vector2* b,
		color* b_color) {
	float x_diff = b->get_x() - a->get_x();
	float y_diff = b->get_y() - a->get_y();
	if (x_diff == 0 && y_diff == 0) {
		s->set_pixel(a->get_x(), a->get_y(), a_color);
		return;
	}
	if (fabs(x_diff) > fabs(y_diff)) {
		float x_min, x_max;
		if (a->get_x() < b->get_x()) {
			x_min = a->get_x();
			x_max = b->get_x();
		} else {
			x_min = b->get_x();
			x_max = a->get_x();
		}
		float slope = y_diff / x_diff;
		for (float x = x_min; x <= x_max; x += (float) 1) {
			float y = a->get_y() + ((x - a->get_x()) * slope);
			color* c = a_color->clone();
			float c_s = (x - a->get_x()) / x_diff;
			color* d = b_color->clone();
			d->subtract(a_color);
			d->multiply(c_s);
			c->add(d);
			s->set_pixel((int) x, (int) y, c);
			delete c;
			delete d;
		}
	} else {
		float y_min, y_max;
		if (a->get_y() < b->get_y()) {
			y_min = a->get_y();
			y_max = b->get_y();
		} else {
			y_min = b->get_y();
			y_max = a->get_y();
		}
		float slope = x_diff / y_diff;
		for (float y = y_min; y <= y_max; y += (float) 1) {
			float x = a->get_x() + ((y - a->get_y()) * slope);
			color* c = a_color->clone();
			float c_s = ((y - a->get_y()) / y_diff);
			color* d = b_color->clone();
			d->subtract(a_color);
			d->multiply(c_s);
			c->add(d);
			s->set_pixel((int) x, (int) y, c);
			delete c;
			delete d;
		}
	}
}

void rasterizer::set_pixel(screen* s, vector2* p, color* c) {
	s->set_pixel((int) p->get_x(), (int) p->get_y(), c);
}

rasterizer::~rasterizer() {
}

