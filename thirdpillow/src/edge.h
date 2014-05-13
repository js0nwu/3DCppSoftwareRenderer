/*
 * edge.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <stdio.h>
#include "vector2.h"
#include "color.h"

class edge {
public:
	edge(vector2 a, color a_color, vector2 b, color b_color);
	vector2* get_a();
	vector2* get_b();
	color* get_a_color();
	color* get_b_color();
	void set_a(vector2* v);
	void set_b(vector2* v);
	void set_a_color(color* c);
	void set_b_color(color* c);

	void print();

	edge* clone();
	virtual ~edge();
private:
	vector2 a;
	vector2 b;
	color a_color;
	color b_color;
};

#endif /* EDGE_H_ */
