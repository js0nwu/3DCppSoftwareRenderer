/*
 * engine.h
 *
 *  Created on: Apr 7, 2014
 *      Author: jwpilly
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "vector3.h"
#include "vector4.h"
#include "transform.h"
#include "world.h"
#include "vertex.h"
#include "rasterizer.h"
#include "putils.h"
#include "screen.h"
#include "rasterizer.h"

using namespace std;

class engine {
public:
	world* get_scene();
	void start();
	void stop();
	void render();
	float* get_render_buffer();
	engine(int render_width, int render_height);
	virtual ~engine();
private:
	world scene;
	transform* player;
	screen* frame;
	rasterizer* rast;
	float RandomFloat(float a, float b);
	void initialize();
	void cleanup();
};

#endif /* ENGINE_H_ */
