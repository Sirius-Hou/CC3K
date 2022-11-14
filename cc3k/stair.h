#ifndef __STAIR_H__
#define __STAIR_H__
#include "mapelement.h"
#include "observer.h"

class Stair: public MapElement, public Observer {
    bool revealed;
public:
    Stair(Coordinate cdn, bool revealed = false);
    int state() override;
    void notify(Subject& whoNotified) override;
    std::string getName() const override;
};


#endif
