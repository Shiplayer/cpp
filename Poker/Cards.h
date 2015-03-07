#ifndef _CARDS_H_
#define _CARDS_H_


#include "Poker.h"

enum Suit {
    clubs, diamonds, hearts, spades
};

class Card {
protected:
    Suit suit;
    int rank;
public:
    Card() {}
};

class OpenCard: Card {
public:
    // Get Rank
    int getRank()const;
    // Get Suit
    Suit getSuit()const;
    OpenCard();
    OpenCard(const Suit, const int);
    bool operator==(OpenCard const&);
    // Card -> String
    std::string toString() const;
};

class CloseCard: Card {
public:
    friend class Poker;
    CloseCard();
    CloseCard(const Suit, const int);
};

#endif // _CARDS_H_