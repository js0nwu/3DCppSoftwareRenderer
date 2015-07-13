/*
 * matrix4.h
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#ifndef MATRIX4_H_
#define MATRIX4_H_

#include <stdlib.h>
#include <stdio.h>
#include "putils.h"
#include "vector3.h"

class matrix4 {
public:
	void print();
	float* get_data();
	float get_at(int x, int y);
	void set_at(int x, int y, float value);
	void initialize_identity();
	void initialize_rotation(float x, float y, float z);
	void initialize_translation(float x, float y, float z);
	void initialize_scale(float x, float y, float z);
	void initialize_projection(float fov, float width, float height, float z_near, float z_far);
	void initialize_camera(vector3 forward, vector3 up);
	void multiply(matrix4 m);
	matrix4();
	matrix4(float* data);
	virtual ~matrix4();

	matrix4* clone();
private:
	float matrix[4][4];
};

#endif /* MATRIX4_H_ */
