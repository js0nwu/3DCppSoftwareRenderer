#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "vector3.h"
class triangle {
public:
	triangle(vector3* a, vector3* b, vector3* c);
	triangle(vector3* vertices);
	vector3* get_vertices();
	void set_vertices(vector3* v);
	virtual ~triangle();
private:
	vector3 vertices[3];
};
#endif