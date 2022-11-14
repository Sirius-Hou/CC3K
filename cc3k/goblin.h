#ifndef __GOBLIN_H_
#define __GOBLIN_H_
#include "npc.h"

class Goblin : public NPC {
public: 
    Goblin(Coordinate cdn);
    std::string getName() const override;
    int attack(int PCDefence) const override;
};

#endif
