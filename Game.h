#ifndef FINAL_GAME_H
#define FINAL_GAME_H

#include <array>
#include "Player.h"
#include "Team.h"
#include "Card.h"

using namespace std;

class Game {
private:
    array<Player *, 4> players;
    Team teams[];
    array<Card *, 52> deck;
public:
    static array<Card *, 52> getDeck() const {

    }
};


#endif //FINAL_GAME_H
