#pragma once
#include "PokeType.h"
#include <string>
class Pokemon;

class Ability {
public:
    int damage;
    PokeType type;
    int usesLeft;
    int  maxUses=usesLeft;
    std::string name;

    Ability() : damage(0), type(PokeType::Normal), usesLeft(0), name("") {}
    Ability(int damage, PokeType type, int usesLeft, const std::string& name)
        : damage(damage), type(type), usesLeft(usesLeft), name(name) {}

    void useAbility(Pokemon& attacker, Pokemon& target);

};