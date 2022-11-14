#ifndef __ITEM_H__
#define __ITEM_H__
#include "cell.h"

class Item : public Cell {
protected:
  bool canStepOn;
public:
  std::string getType() const override;
  Item(Coordinate cdn, bool canStepOn = false);
};

#endif
