/*
 * t_transform.h
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#ifndef t_transform_H_
#define t_transform_H_

#include "vector3.h"
#include "matrix4.h"
#include "camera.h"

class t_transform {
public:
    void translate(vector3* delta);
    matrix4 get_projected_t_transformation();
    matrix4 get_t_transformation();
    void set_translation(vector3* t);
    void set_translation(float x, float y, float z);
    vector3 get_translation();
    void set_rotation(vector3* r);
    void set_rotation(float x, float y, float z);
    vector3 get_rotation();
    void set_scale(vector3* s);
    void set_scale(float x, float y, float z);
    vector3 get_scale();
    static void set_projection(float fov, float width, float height, float z_near, float z_far);
    static void set_camera(camera* c);
    static camera* get_camera();
    t_transform();
    t_transform(vector3 translation, vector3 rotation, vector3 scale);
    virtual ~t_transform();
private:
    static camera* cam;
    vector3 translation;
    vector3 rotation;
    vector3 scale;
};

#endif /* t_transform_H_ */