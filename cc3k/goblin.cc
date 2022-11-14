#include <math.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "goblin.h"
#include "pc.h"

Goblin::Goblin(Coordinate cdn) : NPC{cdn} {
    HP = 70;
    Atk = 5;
    Def = 10;
}

std::string Goblin::getName() const {
    return "Goblin";
}

int Goblin::attack(int PCDefence) const 
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<int> num;
    for (int i = 0; i < 30; i++) {
        num.emplace_back(i);
    }
    std::shuffle(num.begin(), num.end(), std::default_random_engine(seed));
    for (int i = 0; i < 30; i++) {
        int lost = 0;
        if (num[i] < 10) {
            lost = 0;
        } else if (num[i] < 20) {
            lost = 1;
        } else if (num[i] < 30) {
            lost = 2;
        }
        if (PC::coin - lost >= 0) {
            PC::coin -= lost;
            break;
        }
    }
    return ceil((double)100 / (100 + PCDefence) * Atk);
}

