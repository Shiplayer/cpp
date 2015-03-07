#include <iostream>
#include "Board.h"
#include "Poker.h"
#include "Player.h"
#include "Cards.h"
#include "PlayerHuman.h"

//init the board and players
template <typename... Players>
Poker* newGame(uint32_t n, uint32_t startCash, uint32_t littleBlind, Players *... p) {
    Poker* res = new Poker();
    res->playersCount = n;
    res->littleBlind = littleBlind;
    res->deck = std::vector <CloseCard>();
    res->table = std::vector <OpenCard>();

    res->players = new Poker::PlayerData[res->playersCount];
    res->addPlayers(0, p...);

    for (uint32_t i = 0; i < res->playersCount; i++) {
        res->players[i].cash = startCash;
        res->players[i].hand = new OpenCard[2];
    }
    res->shuffle();

    return res;
}

template <typename Player>
void Poker::addPlayers(unsigned cnt, Player* p) {
    if (cnt < playersCount) {
        players[cnt].p = p;
    }
}
//add players
template <typename Player, typename... Team>
void Poker::addPlayers(unsigned cnt, Player* p, Team* ... t) {
    if (cnt < playersCount) {
        players[cnt].p = p;
        addPlayers(++cnt, t...);
    }
}

using namespace std;

//run game
int main() {
    Poker* game = newGame((uint32_t) 2, (uint32_t) 100, (uint32_t) 10, new playerH("FirstPlayer"), new playerH("SecondPlayer"));
    game->run();
    delete game;
    return 0;
}
