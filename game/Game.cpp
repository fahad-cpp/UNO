#include "Game.h"

Game::Game(){
    srand(time(NULL));
    deck = new Deck();
    player = new Player();
    computer = new Computer();
    player->initCards(*deck);
    computer->playSystem.initCards(*deck);
}
Game::~Game(){
    delete computer;
    delete player;
    delete deck;
}
void Game::resetGame(){
    delete computer;
    delete player;
    delete deck;
    deck = new Deck();
    player = new Player();
    computer = new Computer();
}
void Game::printStatus(){
    std::cout << "\nq:quit\n";
    std::cout << "----------------Your-Cards----------------\n";
    player->printCards();
}
int Game::takeInput(int& choice){
    std::string s;
    std::cin >> s;
    int i = std::atoi(s.c_str());
    //pressed q
    if((i==0) && (s == "q")){
        running = false;
        return 1;
    }
    //Out of cards range or not a number
    else if(i <= 0 || i > player->cards.size()){
        std::cout << "Invalid choice\n";
        return 1;
    }
    choice = i;
    return 0;
}
void Game::evaluate(int choice){
    Card chosenCard = player->cards.at(choice-1);
    
    int valid = deck->verify(chosenCard);

    if(valid){
        player->cards.erase(player->cards.begin()+(choice-1));
    }
}
void Game::run(){
    while(running){
        Game::printStatus();
        int choice;
        //Keep taking input until valid input
        if(Game::takeInput(choice) != 0){
            continue;
        }
        Game::evaluate(choice);
    }
}