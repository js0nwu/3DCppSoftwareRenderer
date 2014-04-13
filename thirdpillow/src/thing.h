/*
 * thing.h
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#ifndef THING_H_
#define THING_H_

#include "mesh.h"

class thing {
public:
	void set_mesh(mesh* m);
	mesh* get_mesh();
	thing();
	virtual ~thing();
private:
	mesh* geometry;
};

#endif /* THING_H_ */
