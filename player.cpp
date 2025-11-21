#include "player.h"
#include "energyCard.h"
#include "trainerCard.h"
#include <iostream>

Player::Player(const string& _playerName): 
playerName(_playerName)
{
}

string Player::getPlayerName() const {
    return playerName;
}

vector<Card*>& Player::getBenchCards() {
    return benchCards;
}

vector<PokemonCard*>& Player::getActionCards() {
    return actionCards;
}

void Player::addCardToBench(Card* card) {
    if (card){
        benchCards.push_back(card);
    }
}

void Player::addCardToAction(PokemonCard* card) {
    if (card){
        actionCards.push_back(card);
    }
}

void Player::displayInfo() const {
    cout << "Player: " << playerName << " ==\n";

    cout << "\nBench Cards (" << benchCards.size() << "):\n";
    for (const Card* c : benchCards) {
        if (c) c->displayInfo();
    }

    cout << "\nAction Pokémon (" << actionCards.size() << "):\n";
    for (const PokemonCard* p : actionCards) {
        if (p) p->displayInfo();
    }

    cout << endl;
}

void Player::activatePokemonCard(int benchIndex) {

    Card* card = benchCards[benchIndex];

    PokemonCard* poke = dynamic_cast<PokemonCard*>(card);

    cout << playerName << " is activating a Pokemon Card: " << poke->getName() << "\n";

    // On déplace la carte dans actionCards
    actionCards.push_back(poke);

    // On enlève la carte du banc
    benchCards.erase(benchCards.begin() + benchIndex);
}

void Player::attachEnergyCard(int benchIndex, int attackIndex) {

    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    PokemonCard* pokemon = actionCards[0];
    auto attacks = pokemon->getAttacks(); 

    auto& atk = attacks[attackIndex];
    int cost = get<0>(atk);
    int currentEnergy = get<1>(atk);

    get<1>(atk) = currentEnergy + 1;

    // mise à jour du Pokémon
    pokemon->setAttacks(attacks);

    // retirer l’énergie du banc
    benchCards.erase(benchCards.begin() + benchIndex);

    cout << playerName + " is attaching Energy Card of type " << energy->getEnergyType() << " to the Pokemon " << pokemon->getName() << "\n";
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":\n";

    for (const Card* card : benchCards) {
        card->displayInfo();
    }
}


void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":\n";

    for (const PokemonCard* pokemon : actionCards) {
        if (pokemon) pokemon->displayInfo();
    }
}


void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int opponentPokemonIndex) {
    
    PokemonCard* atkPoke = actionCards[attackerIndex];
    PokemonCard* defPoke = opponent.actionCards[opponentPokemonIndex];

    auto attacks = atkPoke->getAttacks();
    string attackName = get<2>(attacks[attackIndex]);
    int damage = get<3>(attacks[attackIndex]);

    cout << playerName << " attacking " << opponent.playerName << "'s Pokemon " << defPoke->getName() << " with the Pokemon " << atkPoke->getName() << " with its attack: " << attackName << "\n";

    cout << "Reducing " << damage << " from " << opponent.playerName << "'s Pokemon's HP\n";

    defPoke->setHP(defPoke->getHP() - damage);

    if (defPoke->getHP() > 0) {
        cout << "Pokemon " << defPoke->getName() << " is still alive\n";
    }   
}

void Player::useTrainer(int index) {
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);

    cout << playerName << " is using the Trainer Card to \""
         << trainer->getEffect() << "\"\n";

    trainer->applyEffect(actionCards);

    benchCards.erase(benchCards.begin() + index);
}
