#include "passage.h"
Passage::Passage(Coordinate cdn, int passageType): MapElement{cdn}, passageType{passageType} { }

bool Passage::canStep() { return true; }

std::string Passage::getName() const { return "Passage"; }

int Passage::state() { return passageType; }
