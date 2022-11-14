#include "treasure.h"

Treasure::Treasure(Coordinate cdn, int treasure) : Item{cdn, treasure != 9}, treasure{treasure} { }

void Treasure::notify(Subject &Dragon) { canStepOn = true; }

std::string Treasure::getName() const { return "Treasure"; }

int Treasure::state() { return treasure; }

bool Treasure::canStep() {
	return canStepOn;
}

