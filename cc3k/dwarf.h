#ifndef __DWARF_H__
#define __DWARF_H__
#include "pc.h"

class Dwarf: public PC {
public:
    Dwarf(Coordinate cdn);
    std::string getName() const override;
    void applyEffect(int effect) override;
    void applyElimNPCAward() override;
};

#endif
