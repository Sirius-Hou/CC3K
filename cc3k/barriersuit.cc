#include "barriersuit.h"

BarrierSuit::BarrierSuit(Coordinate cdn) : Item{cdn} { }

int BarrierSuit::state() { return 10; }

void BarrierSuit::notify(Subject &Dragon) { canStepOn = true; }

std::string BarrierSuit::getName() const { return "BarrierSuit"; }

bool BarrierSuit::canStep() { return canStepOn; }

