#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Trainer.h"
#include "Pokemon.h"
#include "Ability.h"


int chooseAbility(const Pokemon& activePokemon) {
    std::cout << "Choose an ability for " << activePokemon.name << ":\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << ". " << activePokemon.abilities[i].name << " (Damage: " << activePokemon.abilities[i].damage << ", Uses Left: " << activePokemon.abilities[i].usesLeft << ")\n";
    }

    int choice;
    std::cin >> choice;

    return (choice >= 1 && choice <= 3) ? choice - 1 : 0;
}

void performWildPokemonBattle(Trainer& player, Pokemon& wildPokemon) {
    std::cout << "A wild Pokemon appears!\n";

    while (player.hasPokemon() && wildPokemon.life > 0) {
        player.introduce();
        player.switchPokemon();

        int chosenAbilityIndex;
        std::cout << "Choose an ability to attack:\n";
        chosenAbilityIndex = chooseAbility(player.getActivePokemon());

        player.usePokemonAbility(player.getActivePokemon(), wildPokemon, chosenAbilityIndex);

        if (wildPokemon.life > 0) {
            int wildAbilityIndex = rand() % 4;
            wildPokemon.useAbility(wildPokemon.abilities[wildAbilityIndex], player.getActivePokemon());
        }
    }

    if (wildPokemon.life <= 0) {
        std::cout << "You captured the wild Pokemon!\n";
        player.earnMoneyAndPokeballs(); 
    }
    else {
        std::cout << "All your Pokemon fainted. You blacked out!\n";
    }
}

void performTrainerBattle(Trainer& player, Trainer& opponent) {
    std::cout << "Trainer Battle! " << opponent.firstName << " challenges you!\n";

    while (player.hasPokemon() && opponent.hasPokemon()) {
        player.introduce();
        player.switchPokemon();

        int chosenAbilityIndex;
        std::cout << "Choose an ability to attack:\n";
        chosenAbilityIndex = chooseAbility(player.getActivePokemon());

        player.usePokemonAbility(player.getActivePokemon(), opponent.getActivePokemon(), chosenAbilityIndex);

        if (opponent.getActivePokemon().life > 0) {
            opponent.introduce();
            int opponentAbilityIndex = rand() % 4;
            opponent.usePokemonAbility(opponent.getActivePokemon(), player.getActivePokemon(), opponentAbilityIndex);
        }
    }

    if (!opponent.hasPokemon()) {
        std::cout << "You defeated " << opponent.firstName << "!\n";
        player.earnMoneyAndPokeballs(); 
    }
    else {
        std::cout << "All your Pokemon fainted. You lost the battle!\n";
    }
}
void chooseStartingPokemon(Trainer& player) {
    std::cout << "Choose your starting Pokemon:\n";
    std::cout << "1. Charizard\n";
    std::cout << "2. Venusaur\n";
    std::cout << "3. Blastoise\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        player.team[0] = Pokemon("Charizard", "A fire/flying-type dragon Pokemon", PokeType::Fire, 5, 35,
            Ability(15, PokeType::Fire, 5, "Flamethrower"), Ability(20, PokeType::Normal, 3, "Scratch"),
            Ability(18, PokeType::Flying, 4, "Wing Attack"), Ability(12, PokeType::Normal, 6, "Ember"));
        break;
    case 2:
        player.team[0] = Pokemon("Venusaur", "A grass/poison-type seed Pokemon", PokeType::Grass, 5, 35,
            Ability(14, PokeType::Grass, 5, "Solar Beam"), Ability(18, PokeType::Normal, 3, "Tackle"),
            Ability(16, PokeType::Poison, 4, "Poison Powder"), Ability(10, PokeType::Normal, 6, "Vine Whip"));
        break;
    case 3:
        player.team[0] = Pokemon("Blastoise", "A water-type turtle Pokemon", PokeType::Water, 5, 35,
            Ability(16, PokeType::Water, 5, "Hydro Pump"), Ability(22, PokeType::Normal, 3, "Bite"),
            Ability(20, PokeType::Water, 4, "Bubble Beam"), Ability(14, PokeType::Normal, 6, "Water Gun"));
        break;
    default:
        std::cout << "Invalid choice. Charizard is selected by default.\n";
        player.team[0] = Pokemon("Charizard", "A fire/flying-type dragon Pokemon", PokeType::Fire, 5, 35,
            Ability(15, PokeType::Fire, 5, "Flamethrower"), Ability(20, PokeType::Normal, 3, "Scratch"),
            Ability(18, PokeType::Flying, 4, "Wing Attack"), Ability(12, PokeType::Normal, 6, "Ember"));
        break;
    }

    std::cout << "You chose " << player.team[0].name << "!\n";
}

int main() {
    srand(static_cast<unsigned>(time(0))); 

    Trainer player("Ash", "Ketchum", "I choose you!", 100, 100, 10);
    chooseStartingPokemon(player);


    Pokemon wildPokemon("Pidgey", "A small bird Pokemon", PokeType::Flying, 5, 30,
        Ability(10, PokeType::Normal, 5, "Peck"), Ability(15, PokeType::Flying, 3, "Gust"),
        Ability(12, PokeType::Normal, 4, "Quick Attack"), Ability(8, PokeType::Flying, 6, "Wing Attack"));

    performWildPokemonBattle(player, wildPokemon);


    int actionChoice;
    std::cout << "Do you want to rest?:\n";
    std::cout << "1. No.\n";
    std::cout << "2. Rest\n";
    std::cin >> actionChoice;
    if (actionChoice == 2) {
        player.getActivePokemon().rest();
        std::cout << player.getActivePokemon().name << " rested and restored some energy!\n";
    }

    Trainer opponent("Gary", "Oak", "Smell ya later!", 150, 120, 12); 

    opponent.team[0]= Pokemon("Blastoise", "A water-type turtle Pokemon", PokeType::Water, 5, 25,
        Ability(16, PokeType::Water, 5, "Hydro Pump"), Ability(22, PokeType::Normal, 3, "Bite"),
        Ability(20, PokeType::Water, 4, "Bubble Beam"), Ability(14, PokeType::Normal, 6, "Water Gun"));

    performTrainerBattle(player, opponent);

    return 0;
}