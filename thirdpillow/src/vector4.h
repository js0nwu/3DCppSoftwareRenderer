/*
 * vector4.h
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#ifndef VECTOR4_H_
#define VECTOR4_H_

#include "vector3.h"

class vector4 {
public:
	void set_x(float x);
	void set_y(float y);
	void set_z(float z);
	void set_w(float w);
	float get_x();
	float get_y();
	float get_z();
	float get_w();
	vector4();
	vector4(float x, float y, float z, float w);
	vector4(vector3* v);
	virtual ~vector4();

	vector4* clone();
private:
	float x;
	float y;
	float z;
	float w;
};

#endif /* VECTOR4_H_ */
