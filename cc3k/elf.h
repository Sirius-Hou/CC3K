#ifndef __ELF_H__
#define __ELF_H__
#include "pc.h"

class Elf: public PC {
public:
    Elf(Coordinate cdn);
    std::string getName() const override;
    void applyEffect(int effect) override;
};

#endif
