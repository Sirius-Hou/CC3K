#include "potion.h"

int Potion::state() { return effect; }

std::string Potion::getName() const { return "Potion"; }

Potion::Potion(Coordinate cdn, int effect) : Item{cdn}, effect{effect} { }
