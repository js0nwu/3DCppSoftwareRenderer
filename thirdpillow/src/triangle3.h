#ifndef TRIANGLE_3_H_
#define TRIANGLE_3_H_

#include "vertex.h"
#include "triangle2.h"
#include "transform.h"

class triangle3 {
public:
	triangle3(vector3* a, vector3* b, vector3* c);
	triangle3(vertex* a, vertex* b, vertex* c);
	triangle3(vector3* vertices);
	triangle3(vertex* vertices);
	vector3* get_center();
	vector3* get_normal();
	vertex* get_vertices();
	void set_vertices(vertex* v);
	triangle2* flatten(matrix4* m);
	virtual ~triangle3();
private:
	vertex vertices[3];
	vector3 normal;
	void calculate_normal();
};
#endif