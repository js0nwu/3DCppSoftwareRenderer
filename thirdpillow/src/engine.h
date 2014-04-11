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

#include "camera.h"
#include "world.h"

using namespace std;

class engine {
public:
	void create_camera();
	void create_camera(vector3 position, vector3 rotation);
	void add_camera(camera* c);
	void start();
	void stop();
	void render();
	float* get_render_buffer();
	engine(int render_width, int render_height);
	virtual ~engine();
private:
	vector<camera*> cameras;
	int render_width;
	int render_height;
	float* frame;
	world scene;
	float RandomFloat(float a, float b);
	void initialize();
	void cleanup();
};

#endif /* ENGINE_H_ */
