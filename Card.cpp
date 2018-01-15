#include "Card.h"
bool Card::_deckSet = false;
array<Card *, 52> Card::_deck = {};

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

json Card::serialize() {
    return json(getValue() * 4 + getColor());
}

void Card::setDeck() {
    int i = 0;
    for (const auto cardValue : CardValue::All) {
        for (const auto color : Color::All) {
            _deck[i] = new Card(cardValue, color);
            i++;
        }
    }
    _deckSet = true;
}

array<Card *, 52> Card::getDeck() {
    if (!_deckSet) {
        setDeck();
    }
    return Card::_deck;
}

Card* Card::get(const int id){
    if (!_deckSet) {
        setDeck();
    }
    return Card::_deck[id];
}