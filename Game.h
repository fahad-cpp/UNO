#ifndef GAME_H
#define GAME_H
#include "Core.h"

class Game{
    private:
    Deck* deck;
    Player* player;
    Computer* computer;
    bool running;
    void printStatus();
    void resetGame();
    int takeInput(int& choice);
    void evaluate(int choice);
    public:
    Game();
    ~Game();
    void run();
};
#endif