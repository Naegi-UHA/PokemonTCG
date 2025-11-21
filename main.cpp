#include "card.h"
#include "pokemonCard.h"
#include "energyCard.h"
#include "trainerCard.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{   
    //// Setup des 
    // Pikachu :
    vector<tuple<int,int,string,int>> pikachuAttacks = {
        make_tuple(2, 0, "thunder bolt", 20),
        make_tuple(3, 0, "thunder storm", 30)
    };
    // Bulbasaur :
    vector<tuple<int,int,string,int>> bulbasaurAttacks = {
        make_tuple(2, 0, "Leech Seed", 15),
        make_tuple(3, 0, "Vine Whip", 25)
    };

    Player player1("Hadi");

    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(
        new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, pikachuAttacks)
    );

    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();

    Player player2("Germain");

    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(
        new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, bulbasaurAttacks)
    );

    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);

    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();

    player1.attack(0, 0, player2, 0);
    cout << endl;

    player2.displayAction();
    player2.useTrainer(0);
    cout << endl;
    player2.displayAction();

    return 0;
}
