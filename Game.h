#ifndef FINAL_GAME_H
#define FINAL_GAME_H

#include <array>
#include "Player.h"
#include "Team.h"
#include "Card.h"
#include "Deal.h"
#include "Memento.h"

class Deal;
class Team;

using namespace std;

class Game {
private:
    array<Player *, 4> _players;
    array<Team *, 2> _teams;
	Deal* _currentDeal;
    void setTeams();

public:
	Deal* getCurrentDeal();

    Game();
    Game(array<Player *, 4> players);

    void init();

    void play();

	Memento *makeMemento();

	void reset(Memento *mem);
};


#endif //FINAL_GAME_H
