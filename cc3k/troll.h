#ifndef __TROLL_H_
#define __TROLL_H_
#include "npc.h"

class Troll : public NPC {
public: 
    Troll(Coordinate cdn);
    std::string getName() const override;
    void recoverHP();
};

#endif
