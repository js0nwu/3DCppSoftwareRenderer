/*
 * transform.h
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "vector3.h"
#include "matrix4.h"

class transform {
public:
	void translate(vector3* delta);
	void rotate_degree_xy(float degrees);
	void rotate_degree_yz(float degrees);
	void rotate_degree_xz(float degrees);
	matrix4* get_projected_transformation(float fov, float width, float height, float z_near, float z_far);
	matrix4* get_transformation();
	void set_translation(vector3* t);
	void set_translation(float x, float y, float z);
	vector3* get_translation();
	void set_rotation(vector3* r);
	void set_rotation(float x, float y, float z);
	vector3* get_rotation();
	void set_scale(vector3* s);
	void set_scale(float x, float y, float z);
	vector3* get_scale();
	transform();
	transform(vector3 translation, vector3 rotation, vector3 scale);
	virtual ~transform();
private:
	vector3 translation;
	vector3 rotation;
	vector3 scale;
};

#endif /* TRANSFORM_H_ */
