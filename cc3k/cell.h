#ifndef __CELL_H_
#define __CELL_H_
#include <iostream>
#include "coordinate.h"

class Cell {
    Coordinate cdn;
public:
    Cell(Coordinate cdn);
    void setCdn(Coordinate c);
    virtual int state() = 0;
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual int getHP() const;
    virtual bool canStep();
    virtual int attack(int def) const;
    virtual int attacked(int dmg);
    virtual int getDefence() const;
    virtual ~Cell();
};

#endif


