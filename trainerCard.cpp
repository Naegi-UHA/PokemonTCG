#include "trainerCard.h"
#include <stdio.h>

TrainerCard::TrainerCard(const string& _name, const string& _effect): 
Card(_name), trainerEffect(_effect)
{
}

void TrainerCard::displayInfo() const {
    cout << "trainer Card\n";
    cout << "Name: " << cardName << "\n";
    cout << "Effect: " << trainerEffect << "\n\n";
}

void TrainerCard::applyEffect(vector<PokemonCard*>& pokemons) {

    if (trainerEffect == "heal all your action pokemon") {
        for (PokemonCard* p : pokemons) {
            p->setHP(p->getMaxHP());
        }
    cout << cardName << " healed all your active Pokémon to full HP!\n";
}
    else {
        cout << "invalid effect : " << trainerEffect << "\n";
    }
}

string TrainerCard::getEffect() const{
    return trainerEffect;
}