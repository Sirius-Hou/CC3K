#include "cell.h"

// Constructor
Cell::Cell(Coordinate cdn): cdn{cdn} { }

bool Cell::canStep() {
    return false;
}

int Cell::attack(int def) const {
    return 0;
}

int Cell::attacked(int dmg) {
    return 0;
}

int Cell::getDefence() const{
    return 0;
}

void Cell::setCdn(Coordinate c) {
    cdn = c;
}

int Cell::getHP() const {
    return -1;
}

// Destructor
Cell::~Cell() { };
