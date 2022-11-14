#include "stair.h"

Stair::Stair(Coordinate cdn, bool revealed):
    MapElement{cdn}, revealed{revealed} { }

int Stair::state() {
    if (revealed) {
        return 1;
    } else {
        return 0;
    }
}

void Stair::notify(Subject& whoNotified) {
    revealed = true;
}

std::string Stair::getName() const { return "Stair"; }

