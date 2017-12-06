#ifndef FINAL_TRICK_H
#define FINAL_TRICK_H


#include "Card.h"
#include "Player.h"
#include <list>

using namespace std;

class Trick {
private:
    list<Card*> cards;
    list<Player*> players;
public:
    void addCard();
    Player* getWinner(Contract c);
    Color getStartingColor();
};


#endif //FINAL_TRICK_H
