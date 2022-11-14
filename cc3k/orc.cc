#include "orc.h"

Orc::Orc(Coordinate cdn): PC{cdn} {
    HP = 180;
    maxHP = 180;
    Atk = 30;
    Def = 25;
}

std::string Orc::getName() const { return "Orc"; }

void Orc::applyEffect(int effect) {
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
        coin += (double)1 / 2;
        totalCoin += (double)1 / 2;
    } else if (effect == 7) { // Small Horde
        coin += 2 / 2;
        totalCoin += 2 / 2;
    } else if (effect == 8) { // Merchant Hoard
        coin += 4 / 2;
        totalCoin += 4 / 2;
    } else if (effect == 9) { // Dragon Hoard
        coin += 6 / 2;
        totalCoin += 6 / 2;
    } else if (effect == 10) { // Barrier Suit acquired
        withBarrierSuit = true;
    } else if (effect == 11) { // Compass acquired
        withCompass = true;
    }
}

void Orc::applyElimNPCAward() {
    PC::coin += 0.5;
    PC::totalCoin += 0.5;
}

