#include "wall.h"

Wall::Wall(Coordinate cdn, int wallType): MapElement{cdn}, wallType{wallType} { }

std::string Wall::getName() const {
    return "Wall";
}

int Wall::state() { return wallType; }

