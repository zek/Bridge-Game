#include "Game.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Memento.h"

array<Card *, 52> Game::_deck = {};
bool Game::_deckSet = false;

Deal *Game::getCurrentDeal() {
    return _currentDeal;
}

Game::Game(array<Player *, 4> players) {
    _players = players;
    init();
}

Game::Game() {
    cout << "Welcome to the Bridge Game." << endl << endl;

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
}

void Game::init() {
    setTeams();
    setDeck();

    cout << endl;
    for (const auto team : _teams) {
        cout << *team;
    }
    cout << endl;

    for (Player *player : _players) {
        player->setGame(this);
    }
}

void Game::setDeck() {
    int i = 0;
    for (const auto cardValue : CardValue::All) {
        for (const auto color : Color::All) {
            _deck[i] = new Card(cardValue, color);
            i++;
        }
    }
    _deckSet = true;
}

void Game::setTeams() {
    Team *team1 = new Team("Team 1", _players[0], _players[2]);
    Team *team2 = new Team("Team 2", _players[1], _players[3]);
    _teams = {team1, team2};
}

void Game::play() {
    Memento *mem = Memento::loadFile();
    int dealer = 0;
    bool isFinished = false;
    while (!isFinished) {
        _currentDeal = new Deal(getDeck(), _players, dealer);
        if (mem) {
            _currentDeal->reset(mem);
            mem = nullptr;
        }
        _currentDeal->play();

        cout << _teams[0]->getName() << " : " << _teams[0]->getGameScore() << endl;
        cout << _teams[1]->getName() << " : " << _teams[1]->getGameScore() << endl;

        isFinished = true;
    }
}

array<Card *, 52> Game::getDeck() {
    if (!_deckSet) {
        setDeck();
    }
    return Game::_deck;
}