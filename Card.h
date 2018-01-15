#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include <iostream>
#include "Color.h"
#include "Contract.h"
#include "CardValue.h"
#include "Serializable.h"

using namespace std;

class Card : Serializable {
private:
    CardValue::Type _value;
    Color::Type _color;
    static bool _deckSet;
    static array<Card *, 52> _deck;

public:
    Card(CardValue::Type value, Color::Type color);

    CardValue::Type getValue() const;

    Color::Type getColor() const;

    bool isBigger(Card *rhs, Contract *c);

    friend std::ostream &operator<<(std::ostream &os, const Card &c);

    json serialize() override;

    static void setDeck();

    static array<Card *, 52> getDeck();

    static Card* get(const int id);
};


#endif //FINAL_CARD_H
