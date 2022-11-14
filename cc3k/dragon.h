#ifndef __DRAGON_H_
#define __DRAGON_H_
#include "npc.h"
#include "subject.h"
#include "barriersuit.h"
#include "treasure.h"

class Dragon : public NPC, public Subject {
public: 
    Dragon(Coordinate cdn);
    Dragon(Coordinate cdn, Treasure* t);
    Dragon(Coordinate cdn, BarrierSuit* b);
    std::string getName() const override;
};

#endif
