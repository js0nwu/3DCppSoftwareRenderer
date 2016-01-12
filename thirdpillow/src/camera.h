/*
 * camera.h
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <stdlib.h>
#include <stdio.h>

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix4.h"
#include "inputtable.h"

class camera : public inputtable {
public:
    vector3 y_axis;
    void set_position(vector3* p);
    vector3* get_position();
    vector3* get_left();
    vector3* get_right();
    vector3* get_forward();
    vector3* get_up();
    void rotate_x(float radians);
    void rotate_y(float radians);
    void move(vector3* direction, float amount);
    virtual void input(SDL_Event e);
    float get_fov();
    void set_fov(float f);
    int get_min_x();
    void set_min_x(int i);
    int get_max_x();
    void set_max_x(int i);
    int get_min_y();
    void set_min_y(int i);
    int get_max_y();
    void set_max_y(int i);
    float get_z_near();
    void set_z_near(float f);
    float get_z_far();
    void set_z_far(float f);
    int get_render_width();
    void set_render_width(int i);
    int get_render_height();
    void set_render_height(int i);

    camera(int render_width, int render_height);
    camera(int render_width, int render_height, vector3 pos, vector3 forward, vector3 up);

    virtual ~camera();
private:
    int render_width;
    int render_height;
    vector3 position;
    vector3 forward;
    vector3 up;
    bool active;
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    float z_near;
    float z_far;
    float fov;

    void initialize();
    void cleanup();
};

#endif /* CAMERA_H_ */
