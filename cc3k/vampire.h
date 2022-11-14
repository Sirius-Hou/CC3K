#ifndef __VAMPIRE_H_
#define __VAMPIRE_H_
#include "npc.h"

class Vampire : public NPC {
public: 
    Vampire(Coordinate cdn);
    std::string getName() const override;
    int attack(int PCDefence) const override;
};

#endif
