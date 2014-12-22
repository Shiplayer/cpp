#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>

using namespace std;

class Player{
private:
	static int count;
	string name;
public:
	Player();

	string getName();

	friend ostream& operator<<(const ostream&, const Player&);
	friend istream& operator>>(istream&, const Player&);
};

#endif //__PLAYER_H__
