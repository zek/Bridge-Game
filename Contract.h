#ifndef CONTRACT_H_INCLUDED
#define CONTRACT_H_INCLUDED

class Contract {
    private:
        int _tricksAmount;
        Color _color;
        //Maybe an option, like double, etc ...
        static Contract* _pass;
        Contract();

    public:
        static Contract* const Pass();
        Contract(int amountOfTricks, Color color);
        bool operator>(Contract* c1, Contract* c2);
        bool operator<(Contract* c1, Contract* c2);
        bool operator==(Contract* c1, Contract* c2);
        //void setOption(ContractOption co);
        //ContractOption getContractOption();

};

#endif // CONTRACT_H_INCLUDED
