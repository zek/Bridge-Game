#ifndef TRICK_H_INCLUDED
#define TRICK_H_INCLUDED

class Trick{
    private:
        list<pair<Card*, int>> _cards;

    public:
        Trick();
        void addCard(Card* c, int p);
        int getWinner(Contract* c);
        Color* getStartingColor();

};

#endif // TRICK_H_INCLUDED
