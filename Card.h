#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

class Card{
    private:
        CardValue* _value;
        Color* _color;

    public:
        Card(CardValue* value, Color* color);
        string toString();
};

#endif // CARD_H_INCLUDED
