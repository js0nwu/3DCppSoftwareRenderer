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
#include "transform.h"

using namespace std;

class mesh {
public:
	vector<vertex*> vertices; //how do you spell this
	transform* get_transform();
	mesh();
	virtual ~mesh();
private:
	transform m_transform;
};

#endif /* MESH_H_ */
