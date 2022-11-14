#include <math.h>
#include "npc.h"

int NPC::currInitState = 0;

NPC::NPC(Coordinate cdn) : Cell{cdn} { }

int NPC::getDefence() const { return Def; }

int NPC::attack(int PCDefence) const { return ceil((double)100 / (100 + PCDefence) * Atk); }

int NPC::attacked(int dmg) { // returns the actual damage to NPC
    int actualDmg = dmg;
    if (HP - actualDmg <= 0) {
        actualDmg = HP;
        HP = 0;
        return actualDmg;
    }
    HP -= actualDmg;
    return actualDmg;
}

std::string NPC::getType() const { return "NPC"; }

int NPC::state() { return moved; }

void NPC::setMoved() {
    if (moved == 1) {
        moved = 0;
    } else {
        moved = 1;
    }
}

int NPC::getHP() const { return HP; }
int NPC::getAtk() const { return Atk; }
int NPC::getDef() const { return Def; }

void NPC::setWithCompass(bool b) {
    withCompass = b;
}


bool NPC::getWithCompass() const {
    return withCompass;
}

void NPC::halfHP() {
    HP /= 2;
}

void NPC::moreAtk() {
    Atk *= 1.5;
}
