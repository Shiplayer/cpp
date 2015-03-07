#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Poker.h"
#include "Board.h"

class Board;

class Player {
private:
    std::string name;
public:
    Player() {}
    Player(std::string n) { name = n; }
    // Get Player's name
    std::string getName() const { return name; }
    virtual ~Player() {}
    // Get player's bet or zero
    virtual uint32_t bet(uint32_t minBet, Board state) = 0;
};

#endif //_PLAYER_H_