/*
 * putils.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef PUTILS_H_
#define PUTILS_H_

class putils {
public:
	static int get_index_2d(int x, int y, int wide);
	static int get_index_3d(int x, int y, int z, int wide, int thick);
	static float linear_interpolate(float a, float b, float mu);
};

#endif /* PUTILS_H_ */
