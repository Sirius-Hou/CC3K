#ifndef __MERCHANT_H_
#define __MERCHANT_H_
#include "npc.h"
#include <vector>
class Merchant: public NPC {
    
public: 
    std::vector<int> potions;
    static int hatred; // 0 if not attacked; 1 if attacked
    static void resetHatred();
    static void setHatred();
    Merchant(Coordinate cdn);
    std::string getName() const override;
    int attack(int PCDefence) const override;
    int attacked(int dmg) override;
    ~Merchant();
};

#endif
