#include "human.h"

Human::Human(Coordinate cdn): PC{cdn} {
    HP = 140;
    maxHP = 140;
    Atk = 20;
    Def = 20;
}

std::string Human::getName() const { return "Human"; }


