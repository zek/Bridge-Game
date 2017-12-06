#include "Trick.h"

void Trick::addCard(Card *c, int p) {
    _cards.push_back(pair<Card *, int>(c, p));
}
