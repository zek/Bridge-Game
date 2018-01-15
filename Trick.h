#ifndef TRICK_H_INCLUDED
#define TRICK_H_INCLUDED

#include "Card.h"
#include <vector>
#include "Color.h"
#include "Contract.h"
#include <utility>
#include <list>

using namespace std;

class Trick : public Serializable {
private:
    list<pair<Card *, int>> _cards;

public:
    void addCard(Card *c, int p);

    vector<Card *> getCards();

    int getWinner(Contract *c);

    Color::Type getStartingColor();

    json serialize() override;

    static Trick *unserialize(json data);

};

#endif // TRICK_H_INCLUDED
