#include "mapelement.h"

MapElement::MapElement(Coordinate cdn): Cell{cdn} { }

std::string MapElement::getType() const {
    return "MapElement";
}

int MapElement::state() {
    return -1;
}
