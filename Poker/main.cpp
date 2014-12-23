#include <iostream>
#include "Player.h"
#include "Poker.h"

using namespace std;

int main(){
	int players;
	do{
		cout << "set number players (min 2 and max 10): ";
		cin >> players;
	} while(players < 2 && players > 10);
	Poker poker(players);
	poker.run();
	return 0;
}