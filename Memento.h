#ifndef BRIDGEGAME_MEMENTO_H
#define BRIDGEGAME_MEMENTO_H

#include "Contract.h"
#include "json.hh"
#include "misc.h"
#include "Player.h"
#include <array>
#include <fstream>

using namespace std;

using json = nlohmann::json;

enum class State;
class Deal;
class Contract;
class Player;
class Team;

class Memento {
private:

    int round;
    int first_player;
    json players;
    json contract;
    int contractor = -1;
    State state;
    json teams;

    json _tricksWon;

    void setRound(int value);

    void setTeams(array<Team *, 2> teams);

    void setState(State value);

    void setFirstPlayer(int value);

    void setPlayers(array<Player *, 4> player_list);

    void setContract(Contract *contract, int contractor);

    void saveFile();

    friend class Deal;
    friend class Game;
    friend class Team;

public:
    static Memento* loadFile(int index = -1);

};


#endif