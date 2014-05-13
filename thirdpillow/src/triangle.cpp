#include "triangle.h"

triangle::triangle(vector3* a, vector3* b, vector3* c) {
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

triangle::triangle(vector3* vertices) {
	this->vertices[0] = vertices[0];
	this->vertices[1] = vertices[1];
	this->vertices[2] = vertices[2];
}

triangle::~triangle() {

}