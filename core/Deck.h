#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "Logging.h"
#include <vector>
class Deck{
    public:
    std::vector<Card> cards;
    Deck(bool empty = false);
    void shuffle();
    std::vector<Card> drawCards(int count);
    int verify(Card card);
};
#endif