#include "Game.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Memento.h"
#include "misc.h"
Deal *Game::getCurrentDeal() {
    return _currentDeal;
}

Game::Game(array<Player *, 4> players) {
    _players = players;
    init();
}

Game::Game() {
    cout << AdvancedConsole::Cursor(0, 0) << AdvancedConsole::Erase();
    cout << "Welcome to the Bridge Game." << endl << endl;

    Memento *mem = Memento::loadFile();
    if (mem) {
        cout << "Do you want to load last game?" << endl;
        string q;
        cout << "Yes(y) or No(n) : ";
        getline(std::cin, q);
        if (q == "y" || q == "Y" || q == "yes" || q == "YES") {
            this->reset(mem);
            _currentDeal = new Deal(_players, 0);
            _currentDeal->reset(mem);
            return;
        }
        cout << endl;
    }

    cout << "You should choose either player is a human or a computer. " << endl;
    cout << "If it is a computer, just press ENTER." << endl;
    cout << "If it is a human, just type the player name." << endl << endl;

    string list[4] = {"North", "East", "South", "West"};
    string name;
    for (int i = 0; i < 4; i++) {
        cout << "Player " << list[i] << " : ";
        getline(std::cin, name);
        if (name.empty() || name == "computer") {
            name = "Computer " + list[i];
            _players[i] = new ComputerPlayer(name);
        } else {
            _players[i] = new HumanPlayer(name);
        }
    }
    init();
    makeMemento();
}

void Game::init() {
    _currentDeal = nullptr;
    setTeams();

    cout << endl;
    for (const auto team : _teams) {
        cout << *team;
    }
    cout << endl;


    for (Player *player : _players) {
        player->setGame(this);
    }
}


void Game::setTeams() {
    Team *team1 = new Team("Team 1", _players[0], _players[2]);
    Team *team2 = new Team("Team 2", _players[1], _players[3]);
    _teams = {team1, team2};
}

void Game::play() {
    int dealer = 0;
    bool isFinished = false;
    while (!isFinished) {
        if (!_currentDeal)
            _currentDeal = new Deal(_players, dealer);
        _currentDeal->play();

        cout << _teams[0]->getName() << " : " << _teams[0]->getGameScore() << endl;
        cout << _teams[1]->getName() << " : " << _teams[1]->getGameScore() << endl;

        isFinished = true;
        _currentDeal = nullptr;
    }
}

Memento *Game::makeMemento() {
    auto m = new Memento;
    m->setPlayers(_players);
    m->saveFile();
    return m;
}

void Game::reset(Memento *mem) {
    for (int i = 0; i < 4; i++) {
        if (mem->players[i]["isComputer"] == 1) {
            _players[i] = new ComputerPlayer("");
        } else {
            _players[i] = new HumanPlayer("");
        }
        _players[i]->unserialize(mem->players[i]);
    }
    init();
    _teams[0]->unserialize(mem->teams[0]);
    _teams[1]->unserialize(mem->teams[1]);
}
