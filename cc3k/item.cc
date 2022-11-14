#include "item.h"

Item::Item(Coordinate cdn, bool canStepOn): Cell{cdn}, canStepOn{canStepOn} { }

std::string Item::getType() const { return "Item"; }
