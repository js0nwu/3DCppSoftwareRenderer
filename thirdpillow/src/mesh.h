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
#include "triangle3.h"
#include "transform.h"
#include "putils.h"

using namespace std;

class mesh {
public:
	vector<triangle3> faces;
	transform* get_transform();
	void from_obj(char* filename);
	mesh();
	virtual ~mesh();
private:
	transform m_transform;
};

#endif /* MESH_H_ */
