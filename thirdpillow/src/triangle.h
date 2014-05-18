#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "vertex.h"
class triangle {
public:
	triangle(vector3* a, vector3* b, vector3* c);
	triangle(vertex* a, vertex* b, vertex* c);
	triangle(vector3* vertices);
	triangle(vertex* vertices);
	vector3* get_center();
	vertex* get_vertices();
	void set_vertices(vertex* v);
	virtual ~triangle();
private:
	vertex vertices[3];
};
#endif