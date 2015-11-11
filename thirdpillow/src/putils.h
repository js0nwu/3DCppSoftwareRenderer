/*
 * putils.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef PUTILS_H_
#define PUTILS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstring>

class putils {
public:
    static int get_index_2d(int x, int y, int wide);
    static int get_index_3d(int x, int y, int z, int wide, int thick);
    static float linear_interpolate(float a, float b, float mu);
    static char* read_file(char* filename, int* length);
    static void write_file(char* filename, char* contents);
    static char** split_string(char* text, char* delim, int* length);
    static bool string_contains(char* text, char* find);
    static float to_radians(float degrees);
};

#endif /* PUTILS_H_ */
