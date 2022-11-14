#include "compass.h"

Compass::Compass(Coordinate cdn) : Item{cdn} { canStepOn = true; }

int Compass::state() { return 11; }

std::string Compass::getName() const { return "Compass"; }

bool Compass::canStep() {
    return canStepOn;
}
