#ifndef TRIANGLE_2_H_
#define TRIANGLE_2_H_

#include "vector2.h"
#include <stdlib.h>

class triangle2 {
public:
	triangle2();
	triangle2(vector2* a, vector2* b, vector2* c);
	vector2* get_vertices();
	virtual ~triangle2();
private:
	vector2 vertices[3];
};

#endif