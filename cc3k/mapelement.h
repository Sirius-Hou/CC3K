#ifndef __MAPELEMENT_H__
#define __MAPELEMENT_H__

#include <iostream>
#include "cell.h"

class MapElement: public Cell {
public:
    MapElement(Coordinate cdn);
    std::string getType() const override;
    int state() override;
};



#endif
