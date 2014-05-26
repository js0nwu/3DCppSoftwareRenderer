/*
 * vertex.h
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "vector2.h"
#include "vector3.h"

class vertex {
public:
	void set_position(vector3* p);
	vector3* get_position();
	void set_normal(vector3* p);
	vector3* get_normal();
	void set_uv(vector2* p);
	vector2* get_uv();
	vertex();
	vertex(vector3 position);
	virtual ~vertex();
private:
	vector3 position;
	vector3 normal;
	vector2 uv;
};

#endif /* VERTEX_H_ */
