#ifndef POTION_H
#define POTION_H
#include "item.h"

class Potion : public Item {
    int effect;
public:
  int state() override;
  std::string getName() const override;
  Potion(Coordinate cdn, int effect);
};

#endif
