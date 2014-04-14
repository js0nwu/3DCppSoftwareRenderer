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
	transform();
	transform(vector3 translation);
	virtual ~transform();
private:
	vector3 translation;
};

#endif /* TRANSFORM_H_ */
