#include "Cards.h"
#include <cstdlib>
#include <ctime>

Cards::Cards() : MIN_COLOR(1), MAX_COLOR(4), MIN_NUMBER(2), MAX_NUMBER(14) {

}

Cards::Cards(int color, int number) : MIN_COLOR(1), MAX_COLOR(4), MIN_NUMBER(2), MAX_NUMBER(14) {
	this->color = color;
	this->number = number;
}

Cards Cards::getCards(){
	srand(time(NULL));
	int cardsColor = rand() % MAX_COLOR + MIN_COLOR;
	int cardsNumber = rand() % MAX_NUMBER + MIN_NUMBER;
	return new Cards(cardsColor, cardsNumber);
}