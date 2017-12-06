#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include "Color.h"

enum CARDVALUE {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

class Card {
private:
    CARDVALUE _value;
    COLOR _color;
public:
    Card(CARDVALUE value, COLOR color){
        _value = value;
        _color = color;
    }
};


#endif //FINAL_CARD_H
