#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
    protected:
        string cardName;

    public:
        Card(const string& cardName);
        virtual ~Card() = default;
        virtual void displayInfo() const = 0;

        const string& getName() const;
};

#endif