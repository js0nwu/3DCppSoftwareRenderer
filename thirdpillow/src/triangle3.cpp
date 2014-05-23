#include "triangle3.h"

triangle3::triangle3(vector3* a, vector3* b, vector3* c) {
	vertex* av = new vertex(*a);
	vertex* bv = new vertex(*b);
	vertex* cv = new vertex(*c);
	this->vertices[0] = *av;
	this->vertices[1] = *bv;
	this->vertices[2] = *cv;
}

triangle3::triangle3(vertex* a, vertex* b, vertex* c) {
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

triangle3::triangle3(vector3* vertices) {
	vertex* a = new vertex(vertices[0]);
	vertex* b = new vertex(vertices[1]);
	vertex* c = new vertex(vertices[2]);
	this->vertices[0] = *a;
	this->vertices[1] = *b;
	this->vertices[2] = *c;
}

vertex* triangle3::get_vertices() {
	return &this->vertices[0];
}

vector3* triangle3::get_center() {
	float x = (vertices[0].get_position()->get_x() + vertices[1].get_position()->get_x() + vertices[2].get_position()->get_x()) / 3;
	float y = (vertices[0].get_position()->get_y() + vertices[1].get_position()->get_y() + vertices[2].get_position()->get_y()) / 3;
	float z = (vertices[0].get_position()->get_z() + vertices[1].get_position()->get_z() + vertices[2].get_position()->get_z()) / 3;
	vector3* center = new vector3(x, y, z);
	return center;
}

triangle2* triangle3::flatten(matrix4* m) {
	float x_offset = (float)transform::get_camera()->get_render_width() / (float)2;
	float y_offset = (float)transform::get_camera()->get_render_height() / (float)2;
	float scale = 300;
	float z_offset = (float)0.5;
	vector2* tri2[3];
	for (int i = 0; i < 3; i++) {
		vector4* point = new vector4(this->vertices[i].get_position());
		point->multiply_first(m);
		point->set_x(point->get_x() / point->get_w());
		point->set_y(point->get_y() / point->get_w());
		point->set_z(point->get_z() / point->get_w());
		if (point->get_z() > transform::get_camera()->get_z_near()) {
			point->set_x(point->get_x() / point->get_z());
			point->set_y(point->get_y() / point->get_z());
			float p_x = ((point->get_x() / (float)2) + (float)0.5) * (float)transform::get_camera()->get_render_width();
			float p_y = ((point->get_y() / (float)2) + (float)0.5) * (float)transform::get_camera()->get_render_height();
			vector2* v2 = new vector2(p_x, p_y);
			tri2[i] = v2;
		}
	}
	triangle2* result = new triangle2(tri2[0], tri2[1], tri2[2]);
	return result;
}

triangle3::~triangle3() {

}