#ifndef FINAL_CARD_H
#define FINAL_CARD_H

#include "Color.h"

enum CardValue {
    two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

class Card {
private:
    CardValue _value;
    Color _color;
public:
    Card(CardValue value, Color color){
        _value = value;
        _color = color;
    }
};


#endif //FINAL_CARD_H
