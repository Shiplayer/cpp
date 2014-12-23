#include "Poker.h"

Poker::Poker() {}

Poker::Poker(int numberPlayers) {
	players = new Player[numberPlayers];
	cards = new Cards[5];
}

void Poker::run() {

}