#ifndef SPAN_H_
#define SPAN_H_

#include "color.h"

class span {
public:
	span(color* a, int x_1, color* b, int x_2);
	virtual ~span();
private:
	color a_color;
	color b_color;
	int x_1;
	int x_2;
};

#endif /* SPAN_H_*/