#ifndef FINAL_GAME_H
#define FINAL_GAME_H

#include <array>
#include "Player.h"
#include "Team.h"
#include "Card.h"

using namespace std;

class Game {
private:
    array<Player *, 4> _players;
    array<Team *, 2> _teams;
    array<Card *, 52> _deck;
public:
    static array<Card *, 52> getDeck() const;

    Game(array<Player *, 4> players) : _players(players) {

        Team *team1 = new Team(players[0], players[2]);
        Team *team2 = new Team(players[1], players[3]);
        _teams = {team1, team2};

    }
};


#endif //FINAL_GAME_H
