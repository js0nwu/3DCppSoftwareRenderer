#include "face.h"

face::face(triangle3* tri) {
	this->tri = *tri;
}

triangle3* face::get_triangle() {
	return &this->tri;
}

void face::set_triangle(triangle3* t) {
	this->tri = *t;
}

vector2* face::get_uvs() {
	return &this->uvs[0];
}

void face::set_uvs(vector2* v) {
	this->uvs[0] = v[0];
	this->uvs[1] = v[1];
	this->uvs[2] = v[2];
}

face::~face() {

}