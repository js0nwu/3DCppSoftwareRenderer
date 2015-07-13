#ifndef FACE_H_
#define FACE_H_

#include "vector2.h"
#include "triangle3.h"

class face {
public:
	face(triangle3 tri);
	triangle3 get_triangle();
	void set_triangle(triangle3 t);
	vector2* get_uvs();
	void set_uvs(vector2* v);
	virtual ~face();
private:
	triangle3 tri;
	vector2 uvs[3];
};

#endif