#ifndef __CARDS_H__
#define __CARDS_H__

class Cards {
private:
	int color;
	int number;
	static const int MAX_COLOR;
	static const int MIN_COLOR;
	static const int MAX_NUMBER;
	static const int MIN_NUMBER;

public:
	Cards();
	Cards(int, int);

	Cards getCard();
};

int Cards::MAX_COLOR = 4;
int Cards::MIN_COLOR = 1;
int Cards::MAX_NUMBER = 2;
int Cards::MIN_NUMBER = 14;


#endif //__CARDS_H__