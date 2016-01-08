#ifndef SCREEN_H_
#define SCREEN_H_

#include "color.h"
#include "putils.h"

class screen {
public:
    screen(int render_width, int render_height);
    void set_buffer(unsigned char* buffer);
    unsigned char* get_buffer();
    int get_width();
    int get_height();
    void cls();
    unsigned char get_at(int i);
    void set_at(int i, unsigned char v);
    color get_pixel(int x, int y);
    void set_pixel(int x, int y, color c);
    float* get_z_buffer();
    void set_z_buffer(float* buffer);
    float get_z(int x, int y);
    void set_z(int x, int y, float z);
    virtual ~screen();
private:
    int render_width;
    int render_height;
    unsigned char* buffer;
    float* z_buffer;
};

#endif /* SCREEN_H_ */
