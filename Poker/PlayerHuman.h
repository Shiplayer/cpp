#ifndef _PLAYERHUMAN_H_
#define _PLAYERHUMAN_H_

#include "Board.h"
#include "Player.h"
#include "Cards.h"

class playerH: public Player {
private:
public:
    playerH() {}
    playerH(std::string name): Player(name) { }
    ~playerH() {}
    //make bet, return -1 if bad input(not digits)
    uint32_t bet(uint32_t sum, Board state);
};


#endif //_PLAYERHUMAN_H_