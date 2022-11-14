#ifndef __FLOOR_H__
#define __FLOOR_H__
#include "mapelement.h"

class Floor: public MapElement {
public:
    Floor(Coordinate cdn);
    bool canStep() override;
    std::string getName() const override;
};


#endif
