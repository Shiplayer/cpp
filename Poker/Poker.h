#ifndef _POKER_H_
#define _POKER_H_

#include <vector>

#include "PlayerHuman.h"
#include "Board.h"
#include "Cards.h"

using namespace std;

class OpenCard;

class CloseCard;

class Player;

class Board;

class Poker {
private:
    struct PlayerData {
        uint32_t cash;
        OpenCard *hand;
        uint32_t currBet;
        Player *p;


        ~PlayerData();
    } *players;

    uint32_t playersCount, bank, littleBlind, dealer;

    //print player combination
    void show(Player *p, OpenCard *cards, uint32_t *value);

    string rankToString(uint32_t in);

    // Get id,relevance and kickers of combination
    uint32_t *enter(OpenCard *cards);

    // Get the highest combination
    pair<OpenCard *, uint32_t *> strongestCombination(OpenCard *);

    // Get winners
    vector<uint32_t> show();

    // Player's betting process
    void doBets(uint32_t pls);

    // New round with i's player
    void doRound();

    // Giving new cards
    void shuffle();

    // Checking if player can acces blind
    vector<uint32_t> refresh();

    // Remove card from deck and add to board
    void openNext();

    // Get players who are able to bet
    size_t inGameWithCash();

    // Get state for players[player].p
    Board getTable(uint32_t player, vector<uint32_t> live);

    vector<OpenCard> table;
    vector<CloseCard> deck;

    // Get players in game
    vector<uint32_t> live;

    // Creating new player->adding to instance
    template<typename First>
    void addPlayers(uint32_t cnt, First *first);

    template<typename First, typename... Rest>
    void addPlayers(uint32_t cnt, First *first, Rest *... rest);

    Poker();
    template<typename ... Players>
    friend Poker *newGame(uint32_t n, uint32_t startCash, uint32_t littleBlind,
            Players *... p);



public:
    ~Poker();

    void run();
};

#endif // _POKER_H_