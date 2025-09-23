#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "Deck.h"
#include <vector>
class Player{
    public:
    std::vector<Card> cards;
    Player();
    void initCards(Deck& deck);
    void printCards();
};
#endif