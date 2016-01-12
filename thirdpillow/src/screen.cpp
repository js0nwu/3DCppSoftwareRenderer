#include "screen.h"

screen::screen(int render_width, int render_height) {
    this->render_width = render_width;
    this->render_height = render_height;
    buffer = new unsigned char[render_width * render_height * 3];
    z_buffer = new float[render_width* render_height];
}

void screen::cls() {
    std::fill_n(buffer, render_width * render_height * 3, 0);
    std::fill_n(z_buffer, render_width * render_height, 1);
}

int screen::get_width() {
    return render_width;
}

int screen::get_height() {
    return render_height;
}

void screen::set_buffer(unsigned char* buffer) {
    this->buffer = buffer;
}

unsigned char* screen::get_buffer() {
    return buffer;
}

void screen::set_z_buffer(float* buffer) {
    z_buffer = buffer;
}

float* screen::get_z_buffer() {
    return z_buffer;
}

unsigned char screen::get_at(int i) {
    return buffer[i];
}

void screen::set_at(int i, unsigned char v) {
    buffer[i] = v;
}

color screen::get_pixel(int x, int y) {
    int index = putils::get_index_3d(x, y, 0, render_width, 3);
    color c(buffer[index], buffer[index + 1],
            buffer[index + 2], 1);
    return c;
}

void screen::set_pixel(int x, int y, color c) {
    if (x >= 0 && x < render_width && y >= 0 && y < render_height) {
        int index = putils::get_index_3d(x, y, 0, render_width, 3);
        buffer[index] = c.get_r();
        buffer[index + 1] = c.get_g();
        buffer[index + 2] = c.get_b();
    }
}

float screen::get_z(int x, int y) {
    if (x >= 0 && x < render_width && y >= 0 && y < render_height) {
        int index = putils::get_index_2d(x, y, render_width);
        return z_buffer[index];
    }
}

void screen::set_z(int x, int y, float z) {
    if (x >= 0 && x < render_width && y >= 0 && y < render_height) {
        int index = putils::get_index_2d(x, y, render_width);
        z_buffer[index] = z;
    }
}

screen::~screen() {

}