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
#include "t_transform.h"
#include "putils.h"

class mesh {
public:
    std::vector<face> faces;
    t_transform* get_t_transform();
    void from_obj(char* filename);
    void sort(matrix4* mt);
    mesh();
    virtual ~mesh();
private:
    t_transform m_t_transform;
};

#endif /* MESH_H_ */
