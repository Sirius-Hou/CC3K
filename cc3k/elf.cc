#include "elf.h"

Elf::Elf(Coordinate cdn): PC{cdn} {
    HP = 140;
    maxHP = 140;
    Atk = 30;
    Def = 10;
}

std::string Elf::getName() const { return "Elf"; }

void Elf::applyEffect(int effect) {
    if (effect == 0 || effect == 3) { // Restore Health & Poison Health (negative potions have positive effects)
        if (HP + 10 > maxHP) {
            HP = maxHP;
        } else {
            HP += 10;
        }
    } else if (effect == 1 || effect == 4) { // Boost Atk & Wound Atk (negative potions have positive effects)
        potionAtkEffect += 5;
    } else if (effect == 2 || effect == 5) { // Boost Def & Wound Def (negative potions have positive effects)
        potionDefEffect += 5;
    } else if (effect == 6) { // Normal gold pile
        coin += 1;
    } else if (effect == 7) { // Small Horde
        coin += 2;
    } else if (effect == 8) { // Merchant Hoard
        coin += 4;
    } else if (effect == 9) { // Dragon Hoard
        coin += 6;
    } else if (effect == 10) { // Barrier Suit acquired
        withBarrierSuit = true;
    } else if (effect == 11) { // Compass acquired
        withCompass = true;
    }
}

