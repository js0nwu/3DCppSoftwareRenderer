/*
 * engine.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: jwpilly
 */

#include "engine.h"

void engine::cleanup() {
	printf("cleaning up\n");
	free(this->frame);
}

void engine::initialize() {
	printf("engine initializing\n");
	int size = this->render_width * this->render_height * 3;
	this->frame = (float*)malloc(size * sizeof(float));
}

void engine::start() {
	printf("engine started\n");
	this->initialize();
}

void engine::stop() {
	this->cleanup();
}

void engine::render() {

}

float* engine::get_render_buffer() {
	return this->frame;
}

engine::engine(int render_width, int render_height) {
	printf("engine created (%d, %d)\n", render_width, render_height);
	this->render_width = render_width;
	this->render_height = render_height;
}

engine::~engine() {
	printf("stopping engine\n");
	this->stop();
}

