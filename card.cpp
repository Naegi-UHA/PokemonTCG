#include "card.h"

Card::Card(const string& _cardName):
cardName(_cardName)
{
}

const string& Card::getName() const {
    return cardName;
}