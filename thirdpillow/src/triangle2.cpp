#include "triangle2.h"

triangle2::triangle2() {
	vector2* a = new vector2();
	vector2* b = new vector2();
	vector2* c = new vector2();
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

triangle2::triangle2(vector2* a, vector2* b, vector2* c) {
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

vector2* triangle2::get_vertices() {
	vector2 v[3];
	v[0] = this->vertices[0];
	v[1] = this->vertices[1];
	v[2] = this->vertices[2];
	return &v[0];
}

triangle2::~triangle2() {

}