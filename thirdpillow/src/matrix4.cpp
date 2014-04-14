/*
 * matrix4.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "matrix4.h"

float matrix4::get_at(int x, int y) {
	return this->matrix[x][y];
}

void matrix4::set_at(int x, int y, float value) {
	this->matrix[x][y] = value;
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

float* matrix4::get_data() {
	float* data = new float[16];
	//printf("pointer %p\n", data);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int index = vector2::get_index_2d(i, j, 4);
			data[index] = this->matrix[i][j];
		}
	}
	return data;
}

matrix4* matrix4::clone() {
	matrix4* clone = new matrix4(this->get_data());
	return clone;
}

void matrix4::multiply(matrix4* m) {
	matrix4* product = new matrix4();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			product->set_at(i, j,
					this->matrix[i][0] * m->get_at(0, j)
							+ this->matrix[i][1] * m->get_at(1, j)
							+ this->matrix[i][2] * m->get_at(2, j)
							+ this->matrix[i][3] * m->get_at(3, j));
		}
	}
	float* data = product->get_data();

	for (int i_2 = 0; i_2 < 4; i_2++) {
		for (int j_2 = 0; j_2 < 4; j_2++) {
			int index = vector2::get_index_2d(i_2, j_2, 4);
			this->matrix[i_2][j_2] = data[index];
		}
	}
}

matrix4::matrix4() {
	this->initialize_identity();
}

matrix4::matrix4(float* data) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int index = vector2::get_index_2d(i, j, 4);
			this->matrix[i][j] = data[index];
		}
	}
}

matrix4::~matrix4() {

}

void matrix4::print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("(%d, %d) = %f\n", i, j, this->get_at(i, j));
		}
	}
}

