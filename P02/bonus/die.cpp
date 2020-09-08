#include "die.h"
#include <iostream>


Die::Die (int size) {
    faces = size;
}

void Die::roll () {
    const int MIN_VAL = 1;
    value = (rand()% (faces - MIN_VAL + 1)) + MIN_VAL;
}

int Die::get_face() {
    return faces;
}

int Die::get_value() {
    return value;
}