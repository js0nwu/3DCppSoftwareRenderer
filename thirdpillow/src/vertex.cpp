#include "vertex.h"

void vertex::set_position(vector3 p) {
    position.set_x(p.get_x());
    position.set_y(p.get_y());
    position.set_z(p.get_z());
}

vector3 vertex::get_position() {
    return position;
}

vertex::vertex() {
    // TODO Auto-generated constructor stub

}

vertex::vertex(vector3 position) {
    this->position = position;
}

vertex::~vertex() {
    // TODO Auto-generated destructor stub
}

