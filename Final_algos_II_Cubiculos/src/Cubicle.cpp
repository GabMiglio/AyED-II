#include "../include/Cubicle.h"

Cubicle::Cubicle(int id) {
    this->id = id;
}

int Cubicle::getId() {
    return id;
}

void Cubicle::setId(int id) {
    this->id = id;
}
