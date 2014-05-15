/*
 * mesh.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#include "mesh.h"

transform* mesh::get_transform() {
	return &this->m_transform;
}

mesh* from_obj(char* filename) {
	int n_len;
	char** split_filename = putils::split_string(filename, (char*)".", &n_len);
	char* ext = split_filename[n_len - 1];
	if (strcmp("obj", ext) != 0) {
		printf("file extension is not .obj\n");
		exit(1);
	}
	
}

mesh::mesh() {
	// TODO Auto-generated constructor stub
	transform* t= new transform();
	this->m_transform = *t;
}

mesh::~mesh() {
	// TODO Auto-generated destructor stub
}

