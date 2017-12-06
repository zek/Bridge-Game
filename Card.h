#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include <iostream>
#include "Color.h"
#include "Contract.h"

using namespace std;

namespace CardValue {
    enum Type {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
    };

    static const std::string Values[] = {"2", "3", "4", "5", "6",
                                         "7", "8", "9", "10", "JACK",
                                         "QUEEN", "KING", "ACE"};

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
        return getColor() == c->getColor() && rhs->getColor() != c->getColor();
    }

    friend std::ostream &operator<<(std::ostream &os, const Card &c) {
        return os << Color::Values[c.getColor()] << " " << CardValue::Values[c.getValue()];
    }
};


#endif //FINAL_CARD_H
