#ifndef IMAGE_H_
#define IMAGE_H_

#include "color.h"
#include "putils.h"

class image {
public:
	image();
	image(int width, int height);
	int get_width();
	int get_height();
	color* get_color(int x, int y);
	void set_color(int x, int y, color* value);
	void from_ppm_binary(char* filename);
	void from_ppm_ascii(char* filename); //to do later?
	virtual ~image();
private:
	int width;
	int height;
	color* data;
};

#endif