#ifndef __ORC_H__
#define __ORC_H__
#include "pc.h"

class Orc: public PC {
public:
    Orc(Coordinate cdn);
    std::string getName() const override;
    void applyEffect(int effect) override;
    void applyElimNPCAward() override;
};

#endif
