#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "card.h"
#include "pokemonCard.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TrainerCard : public Card {
private:
    string trainerEffect;

public:
    TrainerCard(const string& name, const string& effect);
    void displayInfo() const override;
    void applyEffect(vector<PokemonCard*>& pokemons);
    string getEffect() const;

};

#endif
