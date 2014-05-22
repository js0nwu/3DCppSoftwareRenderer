/*
 * putils.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "putils.h"

int putils::get_index_2d(int x, int y, int wide) {
	return y * wide + x;
}

int putils::get_index_3d(int x, int y, int z, int wide, int thick) {
	return ((y * wide + x) * thick) + z;
}

float putils::linear_interpolate(float a, float b, float mu) {
	return a * (1 - mu) + b * mu;
}

char* putils::read_file(char* filename, int* length) {
	using namespace std; 

	string line;
	string text = "";
	ifstream file(filename);
	cout << "opening " << filename << endl;
	if (file.is_open()) {
		while (getline(file, line)) {
			text += line;
			text += "\n";
		}
		file.close();
	}
	else {
		cout << "unable to open file" << endl;
		exit(1);
	}
	*length = text.length();
	char* c_s = new char[text.size() + 1];
	c_s[text.size()] = 0;
	memcpy(c_s, text.c_str(), text.size());
	return c_s;
}

void putils::write_file(char* filename, char* contents) {
	using namespace std;

	ofstream output(filename);
	cout << "opening " << filename << endl;
	if (output.is_open()) {
		output << contents;
	}
	else {
		cout << "unable to open file" << endl;
		exit(1);
	}
}
char** putils::split_string(char* text, char* delim, int* length) {
	using namespace std;

	vector<char*> elements;
	size_t pos = 0;
	string s = string(text);
	string delimeter = string(delim);
	string token;
	while ((pos = s.find(delimeter)) != std::string::npos) {
		token = s.substr(0, pos);
		char* c_s = new char[token.size() + 1];
		c_s[token.size()] = 0;
		memcpy(c_s, token.c_str(), token.size());
		elements.push_back(c_s);
		s.erase(0, pos + delimeter.length());
	}
	char* f_c_s = new char[s.size() + 1];
	f_c_s[s.size()] = 0;
	memcpy(f_c_s, s.c_str(), s.size());
	elements.push_back(f_c_s);
	char** c_elems = new char*[sizeof(char*)* elements.size()];
	for (int i = 0; i < elements.size(); i++) {
		c_elems[i] = elements[i];
	}
	*length = elements.size();
	return c_elems;
}