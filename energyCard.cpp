#include "energyCard.h"

EnergyCard::EnergyCard(const string& _energyType): 
Card("Energy"), energyType(_energyType)
{
}

void EnergyCard::displayInfo() const{
    cout << "Energy Card\n";
    cout << "Energy Type: " << energyType << "\n\n";
}

string EnergyCard::getEnergyType() const{
    return energyType;
}