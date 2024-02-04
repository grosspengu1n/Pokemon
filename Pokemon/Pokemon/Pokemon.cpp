#include "Pokemon.h"

void Pokemon::useAbility(Ability& ability, Pokemon& target) {
    ability.useAbility(*this, target);
}

void Pokemon::rest() {
    for (int i = 0; i < 4; ++i) {
        abilities[i].usesLeft = abilities[i].maxUses;
    }

    life = maxHP;

}