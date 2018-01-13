#include "Memento.h"

void Memento::setRound(int value) {
    round = value;
}

void Memento::setFirstPlayer(int value) {
    first_player = value;
}

void Memento::setContract(Contract *contract, int contractor) {
    if (contract) {
        this->contractor = contractor;
        this->contract = contract->serialize();
    }
}

void Memento::setPlayers(array<Player *, 4> player_list) {
    for (Player *player: player_list) {
        players += player->serialize();
    }
}

void Memento::saveFile() {
    json j;
    j["round"] = round;
    j["first_player"] = first_player;
    j["players"] = players;
    j["contractor"] = contractor;
    j["contract"] = contract;
    j["state"] = state;

    std::ofstream o("history.data");
    o << j << std::endl;
}

Memento *Memento::loadFile(int index) {
    try {
        std::ifstream i("history.data");
        json j = json::parse(getLastLine(i));
        Memento *m = new Memento;
        m->round = j["round"];
        m->first_player = j["first_player"];
        m->players = j["players"];
        m->contractor = j["contractor"];
        m->contract = j["contract"];
        m->state = j["state"];
        return m;
    } catch(...) {
        return nullptr;
    }

}

void Memento::setState(State value) {
    state = value;
}
