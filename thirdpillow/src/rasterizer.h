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
#include "triangle3.h"

class rasterizer {
public:
	rasterizer(color* c);
	color* get_default_color();
	void set_default_color(color* c);
	void draw_span(screen* s, span* a, int y);
	void draw_edge_span(screen* s, edge* a, edge* b);
	void draw_triangle_wire(screen* s, vector2* a, vector2* b, vector2* c);
	void draw_triangle_fill(screen* s, vector2* a, vector2* b, vector2* c);

	void draw_triangle_wire_color(screen* s, vector2* a, color* a_color, vector2* b, color* b_color, vector2* c, color* c_color);
	void draw_triangle_fill_color(screen* s, vector2* a, color* a_color, vector2* b, color* b_color, vector2* c, color* c_color);
	void draw_line_color(screen* s, vector2* a, vector2* b, color* c);
	void draw_line_color(screen* s, vector2* a, color* a_color, vector2* b, color* b_color);
	void set_pixel(screen* s, vector2* p, color* c);
	virtual ~rasterizer();
private:
	color default_color;
};

#endif /* RASTERIZER_H_ */
