#include "Trick.h"

void Trick::addCard(Card *c, int p) {
    _cards.push_back(pair<Card *, int>(c, p));
}

COLOR Trick::getStartingColor() {
    if (_cards.size() == 0) {
        return COLOR::NOTRUMP;
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
