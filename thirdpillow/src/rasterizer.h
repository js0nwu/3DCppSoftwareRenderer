/*
 * rasterizer.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include <stdio.h>

#include "color.h"
#include "vector2.h"
#include "screen.h"
#include "edge.h"
#include "span.h"
#include "triangle.h"

class rasterizer {
public:
	rasterizer();
	void draw_span(screen* s, span* a, int y);
	void draw_edge_span(screen* s, edge* a, edge* b);
	void draw_triangle_wire(screen* s, vector2* a, color* a_color, vector2* b, color* b_color, vector2* c, color* c_color);
	void draw_triangle_fill(screen* s, vector2* a, color* a_color, vector2* b, color* b_color, vector2* c, color* c_color);
	void draw_line(screen* s, vector2* a, vector2* b, color* c);
	void draw_line(screen* s, vector2* a, color* a_color, vector2* b, color* b_color);
	void set_pixel(screen* s, vector2* p, color* c);
	virtual ~rasterizer();
};

#endif /* RASTERIZER_H_ */
