#include <math.h>
#include "merchant.h"
#include <random>
#include <chrono>
#include <algorithm>
int Merchant::hatred = 0;

Merchant::Merchant(Coordinate cdn): NPC{cdn} {
    HP = 30;
    Atk = 70;
    Def = 5;
    std::vector<int> randPotions;
    for (int i = 0; i < 6; i++) {
        randPotions.emplace_back(i);
    }
    std::shuffle(randPotions.begin(), randPotions.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    for (int i = 0; i < 3; i++) {
        potions.emplace_back(randPotions[i]);
    }
    randPotions.clear();
}


void Merchant::resetHatred() {
    Merchant::hatred = 0;
}

void Merchant::setHatred() {
    if (Merchant::hatred == 0) {
        Merchant::hatred = 1;
    }
}

int Merchant::attack(int PCDefence) const { 
    if (Merchant::hatred == 0) {
        return 0;
    }
    return ceil(((double)100 / (100 + PCDefence)) * Atk); 
}

std::string Merchant::getName() const {
    return "Merchant";
}


int Merchant::attacked(int dmg) {
    Merchant::hatred = 1;
    int actualDmg = dmg;
    if (HP - actualDmg <= 0) {
        actualDmg = HP;
        HP = 0;
        return actualDmg;
    }
    HP -= actualDmg;
    return actualDmg;
}


Merchant::~Merchant() {
    potions.clear();
}
