#include "Card.h"

Card::Card(CardValue::Type value, Color::Type color) {
    _value = value;
    _color = color;
}

CardValue::Type Card::getValue() const {
    return _value;
}

Color::Type Card::getColor() const {
    return _color;
}

bool Card::isBigger(Card *rhs, Contract *c) {
    if (rhs->getColor() == getColor()) {
        return getValue() > rhs->getValue();
    }
    return getColor() == c->getColor() && rhs->getColor() != c->getColor();
}



std::ostream &operator<<(std::ostream &os, const Card &c) {
    return os << Color::Values[c.getColor()] << " " << CardValue::Values[c.getValue()];
}
