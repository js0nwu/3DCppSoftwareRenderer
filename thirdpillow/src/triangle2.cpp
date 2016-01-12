#include "triangle2.h"

triangle2::triangle2() {
    vertices[0] = vector2();
    vertices[1] = vector2();
    vertices[2] = vector2();
}

triangle2::triangle2(vector2 a, vector2 b, vector2 c) {
    vertices[0] = a;
    vertices[1] = b;
    vertices[2] = c;
}

vector2* triangle2::get_vertices() {
    vector2* v = new vector2[3];
    v[0] = vertices[0];
    v[1] = vertices[1];
    v[2] = vertices[2];
    return v;
}

triangle2::~triangle2() {

}
