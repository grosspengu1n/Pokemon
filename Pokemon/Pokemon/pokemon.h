#pragma once
#include <string>
#include "Ability.h"
#include "PokeType.h"

class Ability; // Forward declaration

class Pokemon {
public:
    std::string name;
    std::string description;
    PokeType type;
    int level;
    int life;
    int maxHP = life;
    Ability abilities[4];

    Pokemon() : name(""), description(""), type(PokeType::Normal), level(0), life(0) {}
    Pokemon(std::string name, std::string description, PokeType type, int level, int life,
        Ability ability1, Ability ability2, Ability ability3, Ability ability4)
        : name(name), description(description), type(type), level(level), life(life) {
        abilities[0] = ability1;
        abilities[1] = ability2;
        abilities[2] = ability3;
        abilities[3] = ability4;
    }

    void rest();

    void useAbility(Ability& ability, Pokemon& target);
};


