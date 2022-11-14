#include "dwarf.h"

Dwarf::Dwarf(Coordinate cdn): PC{cdn} {
    HP = 100;
    maxHP = 100;
    Atk = 20;
    Def = 30;
}

std::string Dwarf::getName() const { return "Dwarf"; }

void Dwarf::applyEffect(int effect) {
    if (effect == 0) { // Restore Health
        if (HP + 10 > maxHP) {
            HP = maxHP;
        } else {
            HP += 10;
        }
    } else if (effect == 1) { // Boost Atk
        potionAtkEffect += 5;
    } else if (effect == 2) { // Boost Def
        potionDefEffect += 5;
    } else if (effect == 3) { // Poison Health
        if (HP - 10 <= 0) {
            HP = 0;
        } else {
            HP -= 10;
        }
    } else if (effect == 4) { // Wound Atk
        potionAtkEffect -= 5;
    } else if (effect == 5) { // Wound Def
        potionDefEffect -= 5;
    } else if (effect == 6) { // Normal gold pile
        coin += 1 * 2;
        totalCoin += 1 * 2;
    } else if (effect == 7) { // Small Horde
        coin += 2 * 2;
        totalCoin += 2 * 2;
    } else if (effect == 8) { // Merchant Hoard
        coin += 4 * 2;
        totalCoin += 4 * 2;
    } else if (effect == 9) { // Dragon Hoard
        coin += 6 * 2;
        totalCoin += 6 * 2;
    } else if (effect == 10) { // Barrier Suit acquired
        withBarrierSuit = true;
    } else if (effect == 11) { // Compass acquired
        withCompass = true;
    }
}

void Dwarf::applyElimNPCAward() {
    PC::coin += 2;
    PC::totalCoin += 2;
}


