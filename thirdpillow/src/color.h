/*
 * color.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef COLOR_H_
#define COLOR_H_

class color {
public:
    color();
    color(float r, float g, float b, float a);
    float get_r();
    float get_g();
    float get_b();
    float get_a();
    void set_r(float r);
    void set_g(float g);
    void set_b(float b);
    void set_a(float a);
    void add(color c);
    void subtract(color c);
    void multiply(float f);

    color* clone();
    virtual ~color();
private:
    float r;
    float g;
    float b;
    float a;
};

#endif /* COLOR_H_ */
