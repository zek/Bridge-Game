#ifndef TRICK_H_INCLUDED
#define TRICK_H_INCLUDED

#include "Card.h"
#include "Color.h"
#include "Contract.h"
#include <utility>
#include <list>

using namespace std;

class Trick {
private:
    list<pair<Card *, int>> _cards;

public:
    void addCard(Card *c, int p);

    int getWinner(Contract *c);

    Color::Type getStartingColor();

};

#endif // TRICK_H_INCLUDED
