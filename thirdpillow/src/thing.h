/*
 * thing.h
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#ifndef THING_H_
#define THING_H_

#include "mesh.h"
#include "transform.h"
#include "image.h"

class thing {
public:
    void set_mesh(mesh* m);
    mesh* get_mesh();
    void set_texture(image* i);
    image* get_texture();
    transform t;
    thing();
    virtual ~thing();
private:
    mesh* geometry;
    image* texture;
};

#endif /* THING_H_ */
