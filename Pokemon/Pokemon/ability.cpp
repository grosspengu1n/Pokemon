#include "Ability.h"
#include "Pokemon.h"
#include <iostream>

void Ability::useAbility(Pokemon& attacker, Pokemon& target) {
    if (usesLeft > 0) {

        int effectiveDamage = damage;

        // resistance/crit
        if (attacker.type == PokeType::Fire && target.type == PokeType::Water) {
            effectiveDamage *= 0.5;
        }
        else {
            effectiveDamage *= 1;
        }



        target.life -= effectiveDamage;

        usesLeft--;

        std::cout << attacker.name << " used " << name << " on " << target.name << " and dealt " << effectiveDamage << " damage!\n";
    }
    else {
        std::cout << "No uses left for this ability!\n";
    }
}