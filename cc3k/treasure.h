#ifndef __TREASURE_H_
#define __TREASURE_H_
#include "item.h"
#include "observer.h"

class Treasure : public Item, public Observer {
    int treasure; // treasure code (6-normal gold pile, ..., 9-dragon horde)

  public:
    int state() override;
    void notify(Subject &Dragon) override;
    std::string getName() const override;
    bool canStep() override;
    Treasure(Coordinate cdn, int treasure);
};

#endif
