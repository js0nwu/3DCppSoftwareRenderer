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
#include "face.h"
#include "transform.h"
#include "putils.h"

using namespace std;

class mesh {
public:
	vector<face> faces;
	transform* get_transform();
	void from_obj(char* filename);
	void sort(matrix4* mt);
	mesh();
	virtual ~mesh();
private:
	transform m_transform;
};

#endif /* MESH_H_ */
