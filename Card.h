#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include "Color.h"
#include "Contract.h"

namespace CardValue {
    enum Type {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
    };

    static const Type All[] = {Type::ACE, Type::TWO, Type::THREE, Type::FOUR, Type::FIVE, Type::SIX,
                               Type::SEVEN, Type::EIGHT, Type::NINE, Type::TEN, Type::JACK,
                               Type::QUEEN, Type::KING};
}


class Card {
private:
    CardValue::Type _value;
    Color::Type _color;
public:
    Card(CardValue::Type value, Color::Type color) {
        _value = value;
        _color = color;
    }

    CardValue::Type getValue() const {
        return _value;
    }

    Color::Type getColor() const {
        return _color;
    }

    bool isBigger(Card *rhs, Contract *c) {
        if (rhs->getColor() == getColor()) {
            return getValue() > rhs->getValue();
        }
        return getColor() == c->getColor();
    }
};


#endif //FINAL_CARD_H
