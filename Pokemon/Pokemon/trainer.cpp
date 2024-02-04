#include "Trainer.h"
#include "Pokemon.h"
#include <iostream>

void performWildPokemonBattle(Trainer& player, Pokemon& wildPokemon); 
void performTrainerBattle(Trainer& player, Trainer& opponent); 

void Trainer::introduce() {
    std::cout << "Trainer " << firstName << " says: " << catchphrase << "\n";
}

void Trainer::captureWildPokemon(Pokemon& wildPokemon) {

    performWildPokemonBattle(*this, wildPokemon);
}

void Trainer::switchPokemon() {

    std::cout << "Switching to " << team[0].name << "!\n";
}

void Trainer::usePokemonAbility(Pokemon& attacker, Pokemon& target, int abilityIndex) {
    if (abilityIndex >= 0 && abilityIndex < 4) {
        attacker.useAbility(attacker.abilities[abilityIndex], target);
    }
    else {
        std::cout << "Invalid ability index!\n";
    }
}

bool Trainer::hasPokemon() {
    for (const auto& pokemon : team) {
        if (pokemon.life > 0) {
            return true;
        }
    }
    return false;
}

Pokemon& Trainer::getActivePokemon() {

    for (auto& pokemon : team) {
        if (pokemon.life > 0) {
            return pokemon;
        }
    }


    throw std::runtime_error("No active Pokemon available.");
}

void Trainer::displayPokemonAbilities() {

    auto activePokemon = getActivePokemon();

    std::cout << "Choose an ability for " << activePokemon.name << ":\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << i + 1 << ". " << static_cast<int>(activePokemon.abilities[i].type) << " Ability\n";
    }
}

void Trainer::earnMoneyAndPokeballs() {
    int earnings = 50; 
    money += earnings;
    numPokeballs += 2; 
    std::cout << "Earned " << earnings << " money and 2 Pokeballs!\n";
}



