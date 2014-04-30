/*
 * putils.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "putils.h"

int putils::get_index_2d(int x, int y, int wide) {
	return y * wide + x;
}

int putils::get_index_3d(int x, int y, int z, int wide, int thick) {
	return ((y * wide + x) * thick) + z;
}

float putils::linear_interpolate(float a, float b, float mu) {
	return a * (1 - mu) + b * mu;
}
