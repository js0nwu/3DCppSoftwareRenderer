#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "vertex.h"
class triangle3 {
public:
	triangle3(vector3* a, vector3* b, vector3* c);
	triangle3(vertex* a, vertex* b, vertex* c);
	triangle3(vector3* vertices);
	triangle3(vertex* vertices);
	vector3* get_center();
	vertex* get_vertices();
	void set_vertices(vertex* v);
	virtual ~triangle3();
private:
	vertex vertices[3];
};
#endif