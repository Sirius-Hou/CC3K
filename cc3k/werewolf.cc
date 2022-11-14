#include "werewolf.h"

Werewolf::Werewolf(Coordinate cdn) : NPC{cdn} {
    HP = 120;
    Atk = 30;
    Def = 5;
}

std::string Werewolf::getName() const {
    return "Werewolf";
}
