#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"

class Ability; // Forward declaration
class Pokemon; // Forward declaration

class Trainer {
public:
    std::string firstName;
    std::string lastName;
    std::string catchphrase;
    int money;
    int lifePoints;
    Pokemon team[6];
    int numPokeballs;

    Trainer() : firstName(""), lastName(""), catchphrase(""), money(0), lifePoints(0), numPokeballs(0) {}
    Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int numPokeballs)
        : firstName(firstName), lastName(lastName), catchphrase(catchphrase), money(money), lifePoints(lifePoints), numPokeballs(numPokeballs) {}

    void introduce();
    void challenge(Trainer& opponent);
    void captureWildPokemon(Pokemon& wildPokemon);
    void switchPokemon();
    void usePokemonAbility(Pokemon& attacker, Pokemon& target, int abilityIndex);
    bool hasPokemon();
    Pokemon& getActivePokemon();

    void displayPokemonAbilities();
    void earnMoneyAndPokeballs();
};


