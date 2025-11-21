#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include <string>
#include "card.h"
#include <vector>
#include <tuple>

using namespace std;

class PokemonCard : public Card
{
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        
        vector< tuple<int , int, string, int> > attacks;

    public:
        PokemonCard(
            const string& name,
            const string& type,
            const string& family,
            int evoLevel,
            int hp, // ici ce paramètre correspond au maxHP initial (voir remarque ci-dessus)
            const vector<tuple<int, int, string, int>>& atkList
        );

        void displayInfo() const override;

        string& getPokemonType();
        string& getFamilyName();
        int getEvolutionLevel();
        int getMaxHP();
        int getHP();
        vector<tuple<int ,int, string, int>> getAttacks();

        void setHP(int newHP);
        void setAttacks(const vector<tuple<int,int,string,int>>& newAttacks);
};

#endif