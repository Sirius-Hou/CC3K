#ifndef __NPC_H__
#define __NPC_H__
#include "cell.h"

class NPC : public Cell {
protected:
    int HP;
    int Atk;
    int Def;
    bool withCompass = false;
    int moved = 0;
public:
    static int currInitState; // if state == currInitState  => NPC has not been moved
    NPC(Coordinate cdn);
    int getDefence() const override;
    int attack(int PCDefence) const override;
    int attacked(int dmg) override;
    std::string getType() const override;
    int state() override;
    void setMoved();
    int getHP() const override;
    int getAtk() const;
    int getDef() const;
    void setWithCompass(bool b);
    bool getWithCompass() const;
    void halfHP();
    void moreAtk();
};

#endif
