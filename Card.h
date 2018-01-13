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
public:
    Card(CardValue::Type value, Color::Type color);

    CardValue::Type getValue() const;

    Color::Type getColor() const;

    bool isBigger(Card *rhs, Contract *c);

    friend std::ostream &operator<<(std::ostream &os, const Card &c);

    json serialize() override {
        return json(getValue() * 4 + getColor());
    }
};


#endif //FINAL_CARD_H
