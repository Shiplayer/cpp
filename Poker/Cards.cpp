#include <sstream>
#include "Board.h"
#include "Cards.h"

using namespace std;

OpenCard::OpenCard() {
    suit = Suit::clubs;
    rank = 0;
}

OpenCard::OpenCard(Suit const x, int const y) {
    suit = x;
    rank = y;
}

int OpenCard::getRank()const {
    return rank;
}


Suit OpenCard::getSuit()const {
    return suit;
}

CloseCard::CloseCard() {}

CloseCard::CloseCard(Suit const x, int const y) {
    suit = x;
    rank = y;
}

bool OpenCard::operator==(OpenCard const &another) {
    return rank == another.getRank() && suit == another.getSuit();
}

string OpenCard::toString() const {
    string rankStr;
    switch (rank) {
        case 14:
            rankStr = "<A>";
            break;
        case 13:
            rankStr = "<K>";
            break;
        case 12:
            rankStr = "<Q>";
            break;
        case 11:
            rankStr = "<J>";
            break;
        default:
        {
            stringstream ss;
            string s;
            ss << rank;
            s = ss.str();
            rankStr =s;
            break;
        }
    }
    string suitChars[] = {"<spades>", "<diamonds>", "<hearts>", "<clubs>"};
    return (rankStr + suitChars[(int) suit]);
}
