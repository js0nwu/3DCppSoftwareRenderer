/*
 * edge.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <stdio.h>
#include "vector2.h"

class edge {
public:
    edge();
    edge(vector2 a, vector2 uv_a, float z_a, vector2 b, vector2 uv_b, float z_b);
    vector2 get_a();
    vector2 get_b();
    vector2 get_uv_a();
    vector2 get_uv_b();
    float get_z_a();
    float get_z_b();
    void set_z_a(float z);
    void set_z_b(float z);
    void set_a(vector2 v);
    void set_b(vector2 v);
    void set_uv_a(vector2 v);
    void set_uv_b(vector2 v);
    void print();

    edge* clone();
    virtual ~edge();
private:
    vector2 a;
    vector2 b;
    vector2 uv_a;
    vector2 uv_b;
    float z_a;
    float z_b;
};

#endif /* EDGE_H_ */
