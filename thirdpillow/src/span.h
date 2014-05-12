#ifndef SPAN_H_
#define SPAN_H_

#include "color.h"

class span {
public:
	span(color a, int x_1, color b, int x_2);
	int get_x_1();
	int get_x_2();
	color* get_a_color();
	color* get_b_color();
	void set_x_1(int i);
	void set_x_2(int i);
	void set_a_color(color* c);
	void set_b_color(color* c);
	virtual ~span();
private:
	color a_color;
	color b_color;
	int x_1;
	int x_2;
};

#endif /* SPAN_H_*/