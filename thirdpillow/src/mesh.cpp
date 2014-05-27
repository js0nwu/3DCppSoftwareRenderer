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

void mesh::from_obj(char* filename) {
	int n_len;
	char** split_filename = putils::split_string(filename, (char*)".", &n_len);
	char* ext = split_filename[n_len - 1];
	if (strcmp("obj", ext) != 0) {
		printf("file extension is not .obj\n");
		exit(1);
	}
	vector<vector3*> positions;
	vector<vector2*> uvs;
	vector<vertex*> vertices;
	int f_len;
	char* model_c = putils::read_file(filename, &f_len);
	int l_len;
	char** lines = putils::split_string(model_c, "\n", &l_len);
	for (int i = 0; i < l_len; i++) {
		char* line = lines[i];
		if (strlen(line) > 0 && line[0] == 'v') {
			int s_len;
			char** line_split = putils::split_string(line, " ", &s_len);
			if (s_len == 4) {
				float a = atof((const char*)line_split[1]);
				float b = atof((const char*)line_split[2]);
				float c = atof((const char*)line_split[3]);
				vector3* m_vertex_v = new vector3(a, b, c);
				vertex* m_vertex = new vertex(*m_vertex_v);
				vertices.push_back(m_vertex);
			}
		}
	}
	for (int j = 0; j < l_len; j++) {
		char* line = lines[j];
		if (strlen(line) > 0 && line[0] == 'f') {
			int s_len;
			char** line_split = putils::split_string(line, " ", &s_len);
			if (s_len == 4) {
				int a = atoi((const char*)line_split[1]);
				int b = atoi((const char*)line_split[2]);
				int c = atoi((const char*)line_split[3]);
				triangle3* face = new triangle3(vertices[a - 1], vertices[b - 1], vertices[c - 1]);
				this->faces.push_back(*face);
			}
		}
	}
}

void mesh::sort() {
	//bubble sort from greatest to least
	for (int it = 0; it < this->faces.size(); it++) {
		for (int i = 0; i < this->faces.size() - 1; i++) {
			int a = i;
			int b = a + 1;
			if (faces[a].get_center()->get_z() < faces[b].get_center()->get_z()) {
				triangle3 temp = faces[a];
				faces[a] = faces[b];
				faces[b] = temp;
			}
		}
	}
}

mesh::mesh() {
	// TODO Auto-generated constructor stub
	transform* t = new transform();
	this->m_transform = *t;
}

mesh::~mesh() {
	// TODO Auto-generated destructor stub
}

