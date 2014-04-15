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
#include "transform.h"
#include "matrix4.h"
#include "world.h"
#include "mesh.h"

class camera {
public:
	void rotate_degree_xy(float degrees);
	void rotate_degree_yz(float degrees);
	void rotate_degree_xz(float degrees);
	void set_position(vector3* p);
	vector3* get_position();
	void set_rotation(vector3* r);
	vector3* get_rotation();
	void translate(vector3* delta);
	static int get_index_3d(int x, int y, int z, int wide, int thick);
	void activate();
	void deactivate();
	float* get_frame();
	bool is_active();
	void set_active(bool state);
	void render(world* scene);
	camera(int render_width, int render_height);
	camera(int render_width, int render_height, vector3 position,
			vector3 rotation);
	virtual ~camera();
private:
	int render_width;
	int render_height;
	vector3 position;
	vector3 rotation;
	bool active;
	float* frame;
	int min_x;
	int max_x;
	int min_y;
	int max_y;
	int min_z;
	int max_z;

	void clear();
	void render_mesh(mesh* m);
	void initialize();
	void cleanup();
};

#endif /* CAMERA_H_ */
