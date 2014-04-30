/*
 * rasterizer.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include "color.h"
#include "vector2.h"
#include "screen.h"

class rasterizer {
public:
	rasterizer();
	void draw_line(screen* s, vector2* a, vector2* b, color* c);
	void draw_line(screen* s, vector2* a, color* a_color, vector2* b, color* b_color);
	virtual ~rasterizer();
};

#endif /* RASTERIZER_H_ */
