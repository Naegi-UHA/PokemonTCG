#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "card.h"
#include <string>
#include <iostream>

class EnergyCard : public Card {
    private:
        string energyType;

    public:
        EnergyCard(const string&);

        void displayInfo() const override;
        string getEnergyType() const;
};

#endif
