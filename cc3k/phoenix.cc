#include "phoenix.h"

Phoenix::Phoenix(Coordinate cdn) : NPC{cdn} {
    HP = 50;
    Atk = 35;
    Def = 20;
}

std::string Phoenix::getName() const {
    return "Phoenix";
}
