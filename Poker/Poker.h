#ifndef __POKER_H__
#define __POKER_H__

#include "Player.h"
#include "Cards.h"

class Poker {
private:
	Player *players;
	Cards *cards;
public:

	Poker();
	Poker(int);

	void run();
};

#endif //__POKER_H__