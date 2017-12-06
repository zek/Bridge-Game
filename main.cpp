#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Game.h"

int main() {

    Player* p1 = new ComputerPlayer("Human");
    Player* p2 = new ComputerPlayer("Computer 1");
    Player* p3 = new ComputerPlayer("Computer 2");
    Player* p4 = new ComputerPlayer("Computer 3");

    array<Player*, 4> players = {p1, p2, p3, p4};

    Game* game = new Game(players);
    game->play();

    return 0;
}