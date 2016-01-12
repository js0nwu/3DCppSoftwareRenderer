/*
 * t_transform.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "t_transform.h"

camera* t_transform::cam;

void t_transform::set_projection(float fov, float width, float height, float z_near, float z_far) {
    t_transform::get_camera()->set_fov(fov);
    t_transform::get_camera()->set_render_width(width);
    t_transform::get_camera()->set_render_height(height);
    t_transform::get_camera()->set_z_near(z_near);
    t_transform::get_camera()->set_z_far(z_far);
}

void t_transform::set_camera(camera* c) {
    t_transform::cam = c;
}

camera* t_transform::get_camera() {
    return t_transform::cam;
}

matrix4 t_transform::get_projected_t_transformation() {
    matrix4 m_t_transformation = get_t_transformation();
    matrix4 m_projection;
    matrix4 camera_rotation;
    camera_rotation.initialize_camera(*t_transform::get_camera()->get_forward(), *t_transform::get_camera()->get_up());
    matrix4 camera_translation;
    camera_translation.initialize_translation(-t_transform::get_camera()->get_position()->get_x(), -t_transform::get_camera()->get_position()->get_y(), -t_transform::get_camera()->get_position()->get_z());
    camera_translation.multiply(m_t_transformation);
    camera_rotation.multiply(camera_translation);
    m_projection.initialize_projection(t_transform::get_camera()->get_fov(), t_transform::get_camera()->get_render_width(), t_transform::get_camera()->get_render_height(), t_transform::get_camera()->get_z_near(), t_transform::get_camera()->get_z_far());
    m_projection.multiply(camera_rotation); //clearly flicker and weird artifacts has something to do with camera_rotation
    return m_projection;
}

matrix4 t_transform::get_t_transformation() {
    matrix4 m_translation;
    m_translation.initialize_translation(translation.get_x(),
                                         translation.get_y(), translation.get_z());
    matrix4 m_rotation;
    m_rotation.initialize_rotation(rotation.get_x(), rotation.get_y(),
                                   rotation.get_z());
    matrix4 m_scale;
    m_scale.initialize_scale(scale.get_x(), scale.get_y(), scale.get_z());
    m_rotation.multiply(m_scale);
    m_translation.multiply(m_rotation);

    matrix4 product = m_translation;
    return product;
}

void t_transform::set_scale(vector3* s) {
    scale = *s;
}

void t_transform::set_scale(float x, float y, float z) {
    vector3* scale = new vector3(x, y, z);
    this->scale = *scale;
}

vector3 t_transform::get_scale() {
    return scale;
}

void t_transform::set_translation(vector3* t) {
    translation = *t; //do you need clone?
}

void t_transform::set_translation(float x, float y, float z) {
    vector3* translation = new vector3(x, y, z);
    this->translation = *translation;
}

vector3 t_transform::get_translation() {
    return translation;
}

void t_transform::set_rotation(vector3* r) {
    rotation = *r; //do you need clone?
}

void t_transform::set_rotation(float x, float y, float z) {
    vector3* rotation = new vector3(x, y, z);
    this->rotation = *rotation;
}

vector3 t_transform::get_rotation() {
    return rotation;
}

void t_transform::translate(vector3* delta) {
    translation.set_x(translation.get_x() + delta->get_x());
    translation.set_y(translation.get_y() + delta->get_y());
    translation.set_z(translation.get_z() + delta->get_z());
    //translation.print
}

t_transform::t_transform(vector3 translation, vector3 rotation, vector3 scale) {
    translation = translation;
    rotation = rotation;
    scale = scale;

}

t_transform::t_transform() {
    // TODO Auto-generated constructor stub
    vector3* translation = new vector3();
    vector3* rotation = new vector3();
    vector3* scale = new vector3(1, 1, 1);
    this->translation = *translation;
    this->rotation = *rotation;
    this->scale = *scale;
}

t_transform::~t_transform() {
    // TODO Auto-generated destructor stub
}

