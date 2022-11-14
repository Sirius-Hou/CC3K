#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include "mapelement.h"

class Passage: public MapElement {
    int passageType; // '#' -> type 1; '+' -> type 2
public:
    Passage(Coordinate cdn, int passageType);
    bool canStep() override;
    std::string getName() const override;
    int state() override;
};

#endif
