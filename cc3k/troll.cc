#include "troll.h"

Troll::Troll(Coordinate cdn) : NPC{cdn} {
    HP = 120;
    Atk = 25;
    Def = 15;
}

std::string Troll::getName() const {
    return "Troll";
}

void Troll::recoverHP() {
    if (HP + 10 <= 120) {
        HP += 10;
    } else {
        HP = 120;
    }
}
