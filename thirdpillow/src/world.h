/*
 * world.h
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <vector>

#include "thing.h"

using namespace std;

class world {
public:
	vector<thing*> things;
	world();
	virtual ~world();
};

#endif /* WORLD_H_ */
