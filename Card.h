#ifndef FINAL_CARD_H
#define FINAL_CARD_H

enum CardValue {
    two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

class Card {
private:
    CardValue value;
    Color color;
public:
    Card(CardValue v, Color c){
        value = v;
        color = c;
    }
};


#endif //FINAL_CARD_H
