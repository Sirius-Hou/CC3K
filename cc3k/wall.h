#ifndef __WALL_H__
#define __WALL_H__
#include "mapelement.h"

class Wall: public MapElement {
    int wallType; // '|' -> type 1;  '-' -> type 2; ' ' -> type 3
public:
    Wall(Coordinate cdn, int wallType);
    std::string getName() const override;
    int state() override;
};


#endif
