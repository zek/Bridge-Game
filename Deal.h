#ifndef DEAL_H_INCLUDED
#define DEAL_H_INCLUDED

#include "Contract.h"
#include "Player.h"
#include "Memento.h"

#include <iostream>
#include <algorithm>

class Player;

class Memento;

using namespace std;

enum class State {
    Dealing, Bidding, Playing, Completed
};

class Deal {
private:
    Contract *_contract;
    Trick *_currentTrick;
    array<Player *, 4> _players;
    int _dealer;
    int _contractor;
    int _round;
    int _first_player;
    array<Card *, 52> _deck;

    State _state;

    void dealing();

    void bidding();

    void playing();

    void scoring();

    int scoreIfWon(int nbrOfOddTricks);

    int scoreIfLost(int nbrOfOddTricks);

public:

    Trick *getCurrentTrick();

    Contract *getContract();

    Deal(array<Card *, 52> deck, array<Player *, 4> players, int dealer);

    void play();

    Memento *makeMemento();

    void reset(Memento *mem);

};

#endif // DEAL_H_INCLUDED
