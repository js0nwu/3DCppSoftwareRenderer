#include "span.h"

span::span(vector2 a, float z_1, int x_1, vector2 b, float z_2, int x_2) {
    if (x_1 > x_2) {
        this->x_2 = x_1;
        uv_a = b;
        this->x_1 = x_2;
        uv_b = a;
        this->z_1 = z_2;
        this->z_2 = z_1;
    }
    else {
        uv_a = a;
        uv_b = b;
        this->x_1 = x_1;
        this->x_2 = x_2;
        this->z_1 = z_1;
        this->z_2 = z_2;
    }
}

int span::get_x_1() {
    return x_1;
}

int span::get_x_2() {
    return x_2;
}

float span::get_z_1() {
    return z_1;
}

float span::get_z_2() {
    return z_2;
}

void span::set_z_1(float z) {
    z_1 = z;
}

void span::set_z_2(float z) {
    z_2 = z;
}

vector2 span::get_uv_a() {
    return uv_a;
}

vector2 span::get_uv_b() {
    return uv_b;
}

void span::set_x_1(int i) {
    x_1 = i;
}

void span::set_x_2(int i) {
    x_2 = i;
}

void span::set_uv_a(vector2 v) {
    uv_a = v;
}

void span::set_uv_b(vector2 v) {
    uv_b = v;
}

span::~span() {

}

