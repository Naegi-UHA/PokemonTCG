#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "pokemonCard.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name);

    string getPlayerName() const;
    vector<Card*>& getBenchCards();
    vector<PokemonCard*>& getActionCards();

    void addCardToBench(Card* card);
    void addCardToAction(PokemonCard* card);

    void displayInfo() const;

    void activatePokemonCard(int benchIndex); // on prend l'index du pokemon du banc qu'on veut activer
    void displayBench() const;
    void displayAction() const;

    void attachEnergyCard(int benchIndex, int attackIndex); // on prend l'index de la carte énergie du banc vers l'index du pokemon qu'on veut
    void attack(int attackerIndex, int attackIndex, Player& opponent, int opponentPokemonIndex);
    void useTrainer(int benchIndex);
};

#endif
