#include "pokemonCard.h"
using namespace std;

PokemonCard::PokemonCard(
    const string& name,
    const string& type,
    const string& family,
    int evoLevel,
    int hp,
    const vector<tuple<int, int, string, int>>& atkList): 
    
    Card(name),
    pokemonType(type),
    familyName(family),
    evolutionLevel(evoLevel),
    maxHP(hp),
    hp(hp),
    attacks(atkList)
{
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card\n";
    cout << "Name: " << cardName << "\n";
    cout << "Type: " << pokemonType << "\n";
    cout << "Family: " << familyName << "\n";
    cout << "Evolution Level: " << evolutionLevel << "\n";
    cout << "Max HP: " << maxHP << "\n";
    cout << "Current HP: " << hp << "\n";

    cout << "\nAttacks:\n";
    for (size_t i = 0; i < attacks.size(); i++) {
        const auto& atk = attacks[i];
        cout << " - Attack " << i + 1 << ":\n";
        cout << "   Energy Cost: " << get<0>(atk) << "\n";
        cout << "   Current Energy: " << get<1>(atk) << "\n";
        cout << "   Description: " << get<2>(atk) << "\n";
        cout << "   Damage: " << get<3>(atk) << "\n";
    }
    cout << endl;
}

// Getters / Setters

string& PokemonCard::getPokemonType() {
    return pokemonType;
}

string& PokemonCard::getFamilyName() {
    return familyName;
}

int PokemonCard::getEvolutionLevel() {
    return evolutionLevel;
}

int PokemonCard::getMaxHP() {
    return maxHP;
}

int PokemonCard::getHP() {
    return hp;
}

vector<tuple<int ,int, string, int>> PokemonCard::getAttacks() {
    return attacks; // retourne une copie
}

void PokemonCard::setHP(int newHP) {
    // on contraint la valeur entre 0 et maxHP
    if (newHP < 0) {
        hp = 0;
    } else if (newHP > maxHP) {
        hp = maxHP;
    } else {
        hp = newHP;
    }
}

void PokemonCard::setAttacks(const vector<tuple<int,int,string,int>>& newAttacks) {
    attacks = newAttacks;
}