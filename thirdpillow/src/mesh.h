/*
 * mesh.h
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#ifndef MESH_H_
#define MESH_H_

#include <vector>

#include "vertex.h"

using namespace std;

class mesh {
public:
	vector<vertex*> vertices; //how do you spell this
	mesh();
	virtual ~mesh();
};

#endif /* MESH_H_ */
