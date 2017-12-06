#ifndef FINAL_GAME_H
#define FINAL_GAME_H

#include <array>
#include "Player.h"
#include "Team.h"
#include "Card.h"
#include "Deal.h"

using namespace std;

class Game {
private:
    array<Player *, 4> _players;
    array<Team *, 2> _teams;

    static array<Card *, 52> _deck;

    void setDeck();

    void setTeams();

public:
    static array<Card *, 52> getDeck() {
        return Game::_deck;
    }

    Game(array<Player *, 4> players);

    void play();
};


#endif //FINAL_GAME_H
