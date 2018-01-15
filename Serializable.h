#ifndef BRIDGEGAME_SERIALIZABLE_H
#define BRIDGEGAME_SERIALIZABLE_H


#include "json.hh"

using json = nlohmann::json;

class Serializable {
public:
    virtual json serialize()=0;
};


#endif