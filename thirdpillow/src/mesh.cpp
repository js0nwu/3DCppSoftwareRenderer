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
	std::vector<vector2*> uvs;
	std::vector<vector3*> vertices;
	int f_len;
	char* model_c = putils::read_file(filename, &f_len);
	int l_len;
	char** lines = putils::split_string(model_c, "\n", &l_len);
	for (int i = 0; i < l_len; i++) {
		char* line = lines[i];
		if (strlen(line) > 0 && line[0] != '#' && putils::string_contains(line, " ")) {
			int s_len;
			char** line_split = putils::split_string(line, " ", &s_len);
			if (s_len == 4) {
				if (strcmp(line_split[0], "v") == 0) {
					float a = atof((const char*)line_split[1]);
					float b = atof((const char*)line_split[2]);
					float c = atof((const char*)line_split[3]);
					vector3* m_vertex_v = new vector3(a, b, c);
					vertices.push_back(m_vertex_v);
				}
			}
			else if (s_len == 3) {
				if (strcmp(line_split[0], "vt") == 0) {
					float u = atof((const char*)line_split[1]);
					float v = atof((const char*)line_split[2]);
					vector2* m_vertex_uv = new vector2(u, v);
					uvs.push_back(m_vertex_uv);
				}
			}
		}
	}
	for (int j = 0; j < l_len; j++) {
		char* line = lines[j];
		if (strlen(line) > 0 && line[0] == 'f') {
			int s_len;
			char** line_split = putils::split_string(line, " ", &s_len);
			if (s_len == 4) {
				int a = 0, b = 0, c = 0;
				int at = 0, bt = 0, ct = 0;
				if (putils::string_contains(line_split[1], "/")) {
					int f_len;
					char** face_split = putils::split_string(line_split[1], "/", &f_len);
					a = atoi((const char*)face_split[0]);
					if (strcmp(face_split[1], "") != 0) {
						at = atoi((const char*)face_split[1]);
					}
				}
				else {
					a = atoi((const char*)line_split[1]);
				}
				if (putils::string_contains(line_split[2], "/")) {
					int f_len;
					char** face_split = putils::split_string(line_split[2], "/", &f_len);
					b = atoi((const char*)face_split[0]);
					if (strcmp(face_split[1], "") != 0) {
						bt = atoi((const char*)face_split[1]);
					}
				}
				else {
					b = atoi((const char*)line_split[2]);
				}
				if (putils::string_contains(line_split[3], "/")) {
					int f_len;
					char** face_split = putils::split_string(line_split[3], "/", &f_len);
					c = atoi((const char*)face_split[0]);
					if (strcmp(face_split[1], "") != 0) {
						ct = atoi((const char*)face_split[1]);
					}
				}
				else {
					c = atoi((const char*)line_split[3]);
				}
				if (a != 0 && b != 0 && c != 0) {
					triangle3 face_t(*vertices[a - 1], *vertices[b - 1], *vertices[c - 1]);
					face f(face_t);
					if (at != 0 && bt != 0 && ct != 0) {
						vector2 f_uvs[3];
						f_uvs[0] = *uvs[at - 1];
						f_uvs[1] = *uvs[bt - 1];
						f_uvs[2] = *uvs[ct - 1];
						f.set_uvs(f_uvs);
					}
					this->faces.push_back(f);
				}
			}
		}
	}
}

void mesh::sort(matrix4* mt) {
	//bubble sort from greatest to least
	//fix this later
	for (int it = 0; it < this->faces.size(); it++) {
		for (int i = 0; i < this->faces.size() - 1; i++) {
			int a = i;
			int b = a + 1;
			if (faces[a].get_triangle().get_center().get_z() < faces[b].get_triangle().get_center().get_z()) {
				face temp = faces[a];
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

