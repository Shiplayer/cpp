#ifndef __CARDS_H__
#define __CARDS_H__

class Cards {
private:
	int color;
	int number;
	const int MAX_COLOR;
	const int MIN_COLOR;
	const int MAX_NUMBER;
	const int MIN_NUMBER;

public:
	Cards();
	Cards(int, int);

	Cards getCard();
};


#endif //__CARDS_H__