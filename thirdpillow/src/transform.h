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
	matrix4* get_transformation();
	void set_translation(vector3* t);
	void set_translation(float x, float y, float z);
	vector3* get_translation();
	void set_rotation(vector3* r);
	void set_rotation(float x, float y, float z);
	vector3* get_rotation();
	transform();
	transform(vector3 translation, vector3 rotation);
	virtual ~transform();
private:
	vector3 translation;
	vector3 rotation;
};

#endif /* TRANSFORM_H_ */
