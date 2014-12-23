#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "Cards.h"

using namespace std;

class Player{
private:
	static int count;
	string name;
	Cards *cards;
	const int MAX_CARDS;
	const int MIN_CARDS;
public:
	Player();

	string getName();

	friend ostream& operator<<(const ostream&, const Player&);
	friend istream& operator>>(istream&, const Player&);
};

#endif //__PLAYER_H__
