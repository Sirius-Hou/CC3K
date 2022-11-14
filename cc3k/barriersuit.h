#ifndef __BARRIERSUIT_H_
#define __BARRIERSUIT_H_
#include "item.h"
#include "observer.h"

class BarrierSuit : public Item, public Observer {
public:
  int state() override;
  void notify(Subject &Dragon) override;
  std::string getName() const override;
  BarrierSuit(Coordinate cdn);
  bool canStep() override;
};

#endif
