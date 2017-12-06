#include "Team.h"

Team::Team(Player *player1, Player *player2) {
    _players = {player1, player2};
    player1->setTeam(this);
    player2->setTeam(this);
}
