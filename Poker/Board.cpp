#include <iostream>
#include <cstdio>
#include "Board.h"
#include "Cards.h"

using namespace std;

Board::Board() {
    hand = nullptr_t();
}

Board::~Board() {
    if (hand != nullptr_t())
        delete[] hand;
}
//print current game situation
void Board::print() const {
    printf("%-15s: %i\n", "Money on board",bank);
    printf("%-15s", "You " );
    printf(": money: %i ,total bet: %i\n", playerCash,playerBet);
    for (uint32_t i = 0; i < enemyCount; i++) {
        printf("%-15s: money: %i ,total bet: %i\n",names[i].c_str(), cash[i],bets[i]);
    }
    if (board.size() != 0) {
        printf("%-15s", "On board" );
        for (uint32_t i = 0; i < board.size(); i++) {
            cout << ": " << board[i].toString() << " ";
        }
        cout << "\n";
    }
    printf("%-15s", "On hand" );
    cout << ": " << hand[0].toString() << ", " << hand[1].toString() << "\n";
}
