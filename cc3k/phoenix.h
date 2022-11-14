#ifndef __PHOENIX_H_
#define __PHOENIX_H_
#include "npc.h"
#include "subject.h"

class Phoenix: public NPC {
public: 
    Phoenix(Coordinate cdn);
    std::string getName() const override;
};

#endif
