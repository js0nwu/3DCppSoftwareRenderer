/*
 * vector3.h
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include "quaternion.h"

class vector3 {
public:
	vector3();
	vector3(float x, float y, float z);
	virtual ~vector3();
	float get_x();
	float get_y();
	float get_z();
	void set_x(float x);
	void set_y(float y);
	void set_z(float z);
	float magnitude();
	float distance_from(vector3 v);
	void normalize();
	void negative();
	float dot_product(vector3 v);
	void cross_product(vector3 v);
	float angle_between(vector3 v);
	void add(float s);
	void add(vector3 v);
	void subtract(float s);
	void subtract(vector3 v);
	void multiply(float s);
	void multiply(vector3 v);
	void divide(float s);
	void divide(vector3 v);
	void scale(vector3 f);
	void lookat(vector3 v);
	void rotate(float degree, vector3 axis);
	void print();
	bool is_zero();

	vector3* clone();
private:
	float x;
	float y;
	float z;
};

#endif /* VECTOR3_H_ */
