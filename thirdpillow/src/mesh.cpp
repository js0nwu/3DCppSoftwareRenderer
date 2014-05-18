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

mesh* mesh::from_obj(char* filename) {
	int n_len;
	char** split_filename = putils::split_string(filename, (char*)".", &n_len);
	char* ext = split_filename[n_len - 1];
	if (strcmp("obj", ext) != 0) {
		printf("file extension is not .obj\n");
		exit(1);
	}
	vector<vertex*> vertices;
	mesh* m = new mesh();
	int f_len;
	char* model_c = putils::read_file(filename, &f_len);
	int l_len;
	char** lines = putils::split_string(model_c, "\n", &l_len);
	for (int i = 0; i < l_len; i++) {
		char* line = lines[i];
		if (line[0] == 'v') {
			int s_len;
			char** line_split = putils::split_string(line, " ", &s_len);
			if (s_len == 4) {
				float a = atof((const char*)line[1]);
				float b = atof((const char*)line[2]);
				float c = atof((const char*)line[3]);
				vector3* m_vertex_v = new vector3(a, b, c);
				vertex* m_vertex = new vertex(*m_vertex_v);
				vertices.push_back(m_vertex);
			}
		}
	}
	for (int j = 0; j < l_len; j++) {
		char* line = lines[j];
		if (line[0] == 'f') {
			int s_len;
			char** line_slit = putils::split_string(line, " ", &s_len);
			if (s_len == 4) {
				int a = atoi((const char*)line[1]);
				int b = atoi((const char*)line[2]);
				int c = atoi((const char*)line[3]);
				triangle* face = new triangle(vertices[a], vertices[b], vertices[c]);
				m->faces.push_back(face);
			}
		}
	}
	return m;
}

mesh::mesh() {
	// TODO Auto-generated constructor stub
	transform* t = new transform();
	this->m_transform = *t;
}

mesh::~mesh() {
	// TODO Auto-generated destructor stub
}

