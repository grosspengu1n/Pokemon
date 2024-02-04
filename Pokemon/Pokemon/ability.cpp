#include "Ability.h"
#include "Pokemon.h"
#include <iostream>

void Ability::useAbility(Pokemon& attacker, Pokemon& target) {
    if (usesLeft > 0) {

        int effectiveDamage = damage;

        // resistance/crit
        if (attacker.type == target.type) {
            effectiveDamage *= 1;
        }
        else {
            effectiveDamage *= 0.5; 
        }

        target.life -= effectiveDamage;

        usesLeft--;

        std::cout << attacker.name << " used " << name << " on " << target.name << " and dealt " << effectiveDamage << " damage!\n";
    }
    else {
        std::cout << "No uses left for this ability!\n";
    }
}