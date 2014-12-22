#include "Player.h"

int Player::count = 1;

Player::Player() {
	name = "Player" + count;
}
