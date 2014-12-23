#include "Player.h"

int Player::count = 1;

Player::Player() : MIN_CARDS(2), MAX_CARDS(5) {
	name = "Player" + count;
}
