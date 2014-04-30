/*
 * screen.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "color.h"
#include "putils.h"

class screen {
public:
	screen(int render_width, int render_height);
	void set_buffer(float* buffer);
	float* get_buffer();
	int get_width();
	int get_height();
	void cls();
	float get_at(int i);
	void set_at(int i, float f);
	color* get_pixel(int x, int y);
	void set_pixel(int x, int y, color* c);
	virtual ~screen();
private:
	int render_width;
	int render_height;
	float* buffer;
};

#endif /* SCREEN_H_ */
