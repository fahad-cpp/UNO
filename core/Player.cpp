#include "Player.h"
Player::Player(){
    this->cards = {};
}
void Player::initCards(Deck& deck){
    this->cards = deck.drawCards(7);
}
void Player::printCards(){
    int counter = 1;
    for(const Card& card : this->cards){
        std::cout << "\t\t";
        std::cout << counter << ".";
        printCard(card);
        std::cout << "\n";
        counter++;
    }
}