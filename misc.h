#ifndef BRIDGEGAME_MISC_H
#define BRIDGEGAME_MISC_H

#include  <random>
#include  <iterator>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "advconsole/advconsole.h"

using namespace std;

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator &g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}


std::istream& ignoreline(std::ifstream& in, std::ifstream::pos_type& pos);

std::string getLastLine(std::ifstream& in);

#endif //BRIDGEGAME_MISC_H
