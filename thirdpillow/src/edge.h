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

class edge {
public:
	edge(vector2 a, vector2 uv_a, vector2 b, vector2 uv_b);
	vector2* get_a();
	vector2* get_b();
	vector2* get_uv_a();
	vector2* get_uv_b();
	void set_a(vector2* v);
	void set_b(vector2* v);
	void set_uv_a(vector2* v);
	void set_uv_b(vector2* v);
	void print();

	edge* clone();
	virtual ~edge();
private:
	vector2 a;
	vector2 b;
	vector2 uv_a;
	vector2 uv_b;
};

#endif /* EDGE_H_ */
