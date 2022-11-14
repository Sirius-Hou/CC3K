#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "pc.h"

class Human: public PC {
public:
    Human(Coordinate cdn);
    std::string getName() const override;
};



#endif
