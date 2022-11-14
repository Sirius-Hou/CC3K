#ifndef _COMPASS_H_
#define _COMPASS_H_
#include "item.h"


class Compass : public Item {
public:
  int state() override;
  std::string getName() const override;
  Compass(Coordinate cdn);
  bool canStep() override;
};

#endif
