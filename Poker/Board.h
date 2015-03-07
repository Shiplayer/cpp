#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

#include "Cards.h"

//class OpenCard;

class Board {
public:
    uint32_t enemyCount, bank, littleBlind, playerCash, playerBet;
    OpenCard *hand;
    std::vector <OpenCard> board;
    std::vector <std::string> names;
    std::vector <uint32_t> cash, bets;
    Board();
    ~Board();
    //print current game situation
    void print() const;
};

#endif //_BOARD_H_
