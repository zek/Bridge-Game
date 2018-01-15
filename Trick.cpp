#include "Trick.h"
#include "Game.h"

void Trick::addCard(Card *c, int p) {
    _cards.emplace_back(c, p);
}

Color::Type Trick::getStartingColor() {
    if (_cards.empty()) {
        return Color::NOTRUMP;
    } else {
        return _cards.front().first->getColor();
    }
}

int Trick::getWinner(Contract *c) {
    std::list<pair<Card *, int>>::iterator it = _cards.begin();
    pair<Card *, int> biggest = *it;
    for (++it; it != _cards.end(); ++it) {
        if (it->first->isBigger(biggest.first, c)) {
            biggest = *it;
        }
    }
    return biggest.second;
}


vector<Card *> Trick::getCards() {
    vector<Card *> cardsOnTable;
    if (_cards.empty()) {
        return cardsOnTable;
    } else {
        std::list<pair<Card *, int>>::iterator it = _cards.begin();
        for (++it; it != _cards.end(); ++it) {
            cardsOnTable.push_back(it->first);
        }
        return cardsOnTable;
    }
}

json Trick::serialize() {
    json cards;
    for (auto c: _cards) {
        cards += {c.second, c.first->serialize()};
    }
    return cards;
}

Trick *Trick::unserialize(json data) {
    Trick *t = new Trick;

    for (const auto &c: data) {
        t->addCard(Card::get(c[1]), c[0]);
    }

    return t;
}
