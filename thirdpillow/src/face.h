#ifndef FACE_H_
#define FACE_H_

#include "vector2.h"
#include "triangle3.h"

class face {
public:
	face(triangle3* tri);

	virtual ~face();
private:
	triangle3 tri;
	vector2 uvs[3];
};

#endif