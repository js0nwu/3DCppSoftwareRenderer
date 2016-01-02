/*
 * rasterizer.h
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include <stdio.h>
#include <thread>

#ifndef __APPLE__
#include <omp.h>
#endif

#include "color.h"
#include "vector2.h"
#include "screen.h"
#include "edge.h"
#include "span.h"
#include "triangle2.h"
#include "mesh.h"
#include "matrix4.h"
#include "image.h"
#include "putils.h"

class rasterizer {
public:
    rasterizer(color c);
    color get_default_color();
    void set_default_color(color c);
    void draw_span(screen s, span a, image* texture, int y);
    void draw_edge_span(screen s, edge a, edge b, image* texture);
    void draw_triangle_wire(screen s, vector2 a, vector2 b, vector2 c);
    void draw_triangle_wire(screen s, triangle2 t);
    void draw_triangle_wire_color(screen s, vector2 a, color a_color, vector2 b, color b_color, vector2 c, color c_color);
    void draw_line_color(screen s, vector2 a, vector2 b, color c);
    void draw_triangle3_wire(screen s, triangle3 t3, matrix4 mt);
    void draw_face_textured(screen s, face f, image* texture, matrix4 mt);
    void draw_line_color(screen s, vector2 a, color a_color, vector2 b, color b_color);
    void draw_mesh_wire(screen s, mesh m, matrix4 mt);
    void draw_mesh_wire_cull(screen s, mesh m, matrix4 mt);
    void draw_mesh_normals(screen s, mesh m, matrix4 mt);
    void draw_mesh_textured(screen s, mesh m, image* texture, matrix4 mt);
    void draw_mesh_textured_cull(screen s, mesh m, image* texture, matrix4 mt);
    void draw_image(screen s, image texture);
    void set_pixel(screen s, vector2 p, color c);
    virtual ~rasterizer();
private:
    color default_color;
};

#endif /* RASTERIZER_H_ */
