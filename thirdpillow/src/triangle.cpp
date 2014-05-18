#include "triangle.h"

triangle::triangle(vector3* a, vector3* b, vector3* c) {
	vertex* av = new vertex(*a);
	vertex* bv = new vertex(*b);
	vertex* cv = new vertex(*c);
	this->vertices[0] = *av;
	this->vertices[1] = *bv;
	this->vertices[2] = *cv;
}

triangle::triangle(vertex* a, vertex* b, vertex* c) {
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

triangle::triangle(vector3* vertices) {
	vertex* a = new vertex(vertices[0]);
	vertex* b = new vertex(vertices[1]);
	vertex* c = new vertex(vertices[2]);
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

vertex* triangle::get_vertices() {
	return &this->vertices[0];
}

triangle::~triangle() {

}