/*
 * vertex.h
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "vector3.h"

class vertex {
public:
	void set_position(vector3* p);
	vector3* get_position();
	vertex();
	vertex(vector3 position);
	virtual ~vertex();
private:
	vector3 position;
};

#endif /* VERTEX_H_ */
