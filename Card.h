#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include <iostream>
#include "Color.h"
#include "Contract.h"
#include "CardValue.h"

using namespace std;

class Card {
private:
    CardValue::Type _value;
    Color::Type _color;
public:
    Card(CardValue::Type value, Color::Type color);

    CardValue::Type getValue() const;

    Color::Type getColor() const;

    bool isBigger(Card *rhs, Contract *c);
    
    friend std::ostream &operator<<(std::ostream &os, const Card &c);
};


#endif //FINAL_CARD_H
