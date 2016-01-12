/*
 * vector2.h
 *
 *  Created on: Apr 8, 2014
 *      Author: jwpilly
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <math.h>

class vector2 {
public:
    vector2();
    vector2(float x, float y);
    virtual ~vector2();
    float get_x();
    float get_y();
    void set_x(float x);
    void set_y(float y);
    float magnitude();
    float distance_from(vector2 v);
    void normalize();
    void negative();
    float dot_product(vector2 v);
    void cross_product(vector2 v);
    float angle_between(vector2 v);
    void rotate(float radians);
    void add(float s);
    void add(vector2 v);
    void subtract(float s);
    void subtract(vector2 v);
    void multiply(float s);
    void multiply(vector2 v);
    void divide(float s);
    void divide(vector2 v);
    void scale(vector2 f);
    static int get_index_2d(int x, int y, int wide);

    vector2* clone();
private:
    float x;
    float y;
};

#endif /* VECTOR2_H_ */
