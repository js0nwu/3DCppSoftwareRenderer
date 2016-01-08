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
    color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    unsigned char get_r();
    unsigned char get_g();
    unsigned char get_b();
    unsigned char get_a();
    void set_r(unsigned char r);
    void set_g(unsigned char g);
    void set_b(unsigned char b);
    void set_a(unsigned char a);
    void add(color c);
    void subtract(color c);
    void multiply(unsigned char f);

    color* clone();
    virtual ~color();
private:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

#endif /* COLOR_H_ */
