#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include "Color.h"
#include "Contract.h"

enum CARDVALUE {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

class Card {
private:
    CARDVALUE _value;
    COLOR _color;
public:
    Card(CARDVALUE value, COLOR color) {
        _value = value;
        _color = color;
    }

    CARDVALUE getValue() const {
        return _value;
    }

    COLOR getColor() const {
        return _color;
    }

    bool isBigger(Card *rhs, Contract *c) {
        if (rhs->getColor() == getColor()) {
            return getValue() > rhs->getColor();
        }
        return getColor() == c->getColor();
    }
};


#endif //FINAL_CARD_H
