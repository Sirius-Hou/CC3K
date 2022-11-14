#include <math.h>
#include "pc.h"
#include "vampire.h"

Vampire::Vampire(Coordinate cdn) : NPC{cdn} {
    HP = 50;
    Atk = 25;
    Def = 25;
}

std::string Vampire::getName() const {
    return "Vampire";
}

int Vampire::attack(int PCDefence) const 
{
    if (HP + 5 <= 50) {
        PC::HP += 5;
    } else {
        PC::HP = 50;
    }
    return ceil((double)100 / (100 + PCDefence) * Atk);
}
