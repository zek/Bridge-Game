#ifndef DEAL_H_INCLUDED
#define DEAL_H_INCLUDED

class Deal {
    private:
        Contract* _contract;
        array<Player*, 4> _players;
        int _dealer;
        int _contractor;
        array<Card*, 52> _deck;
        void dealing();
        void bidding();
        void playing();
        void scoring();




    public:
        Deal(array<Card*, 52> deck, array<Player*, 4> players, int dealer);
        void play();
};

#endif // DEAL_H_INCLUDED
