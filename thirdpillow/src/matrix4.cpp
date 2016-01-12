/*
 * matrix4.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "matrix4.h"

float matrix4::get_at(int x, int y) {
    return matrix[x][y];
}

void matrix4::set_at(int x, int y, float value) {
    matrix[x][y] = value;
}

void matrix4::initialize_rotation(float x, float y, float z) {
    initialize_identity();
    matrix4 rx, ry, rz;
    rx.initialize_identity();
    ry.initialize_identity();
    ry.initialize_identity();
    float x_radians = putils::to_radians(x);
    float y_radians = putils::to_radians(y);
    float z_radians = putils::to_radians(z);
    rz.set_at(0, 0, cos(z_radians));
    rz.set_at(0, 1, -sin(z_radians));
    rz.set_at(1, 0, sin(z_radians));
    rz.set_at(1, 1, cos(z_radians));

    rx.set_at(1, 1, cos(x_radians));
    rx.set_at(2, 1, sin(x_radians));
    rx.set_at(1, 2, -sin(x_radians));
    rx.set_at(2, 2, cos(x_radians));

    ry.set_at(0, 0, cos(y_radians));
    ry.set_at(2, 0, sin(y_radians));
    ry.set_at(0, 2, -sin(y_radians));
    ry.set_at(2, 2, cos(y_radians));

    ry.multiply(rx);
    rz.multiply(ry);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = rz.get_at(i, j);
        }
    }

}

void matrix4::initialize_translation(float x, float y, float z) {
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = x;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[1][3] = y;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    matrix[2][3] = z;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

void matrix4::initialize_scale(float x, float y, float z) {
    matrix[0][0] = x;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = y;
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = z;
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

void matrix4::initialize_identity() {
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

void matrix4::initialize_projection(float fov, float width, float height,
                                    float z_near, float z_far) {
    float ar = width / height;
    float tan_half_fov = tanf((fov / (float)2) * ((float) 3.14 / (float)180));
    float z_range = z_near - z_far;
    matrix[0][0] = (float)1 / (tan_half_fov * ar);
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = (float)1 / (tan_half_fov);
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = (-z_near - z_far) / z_range;
    matrix[2][3] = 2 * z_far * z_near / z_range;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 1;
    matrix[3][3] = 0;
}

void matrix4::initialize_camera(vector3 forward, vector3 up) {
    forward.normalize();
    vector3 f = forward;
    up.normalize();
    vector3 r = up;
    r.normalize();
    r.cross_product(f);
    vector3 u = f;
    u.cross_product(r);
    initialize_identity();
    set_at(0, 0, r.get_x());
    set_at(0, 1, r.get_y());
    set_at(0, 2, r.get_z());
    set_at(1, 0, u.get_x());
    set_at(1, 1, u.get_y());
    set_at(1, 2, u.get_z());
    set_at(2, 0, f.get_x());
    set_at(2, 1, f.get_y());
    set_at(2, 2, f.get_z());
}

float* matrix4::get_data() {
    float* data = new float[16];
    //printf("pointer %p\n", data);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int index = putils::get_index_2d(i, j, 4);
            data[index] = matrix[i][j];
        }
    }
    return data;
}

matrix4* matrix4::clone() {
    matrix4* clone = new matrix4(get_data());
    return clone;
}

void matrix4::multiply(matrix4 m) {
    matrix4 product;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            product.set_at(i, j,
                           matrix[i][0] * m.get_at(0, j)
                           + matrix[i][1] * m.get_at(1, j)
                           + matrix[i][2] * m.get_at(2, j)
                           + matrix[i][3] * m.get_at(3, j));
        }
    }
    float* data = product.get_data();

    for (int i_2 = 0; i_2 < 4; i_2++) {
        for (int j_2 = 0; j_2 < 4; j_2++) {
            int index = putils::get_index_2d(i_2, j_2, 4);
            matrix[i_2][j_2] = data[index];
        }
    }

    delete data;
}

matrix4::matrix4() {
    initialize_identity();
}

matrix4::matrix4(float* data) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int index = putils::get_index_2d(i, j, 4);
            matrix[i][j] = data[index];
        }
    }
}

matrix4::~matrix4() {
}
void matrix4::print() {
    printf("matrix4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("(%d, %d) = %f\n", i, j, get_at(i, j));
        }
    }
}
