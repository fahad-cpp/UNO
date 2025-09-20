#include "Deck.h"
#include <iostream>
#include <random>
#include <algorithm>
Deck::Deck(bool empty){
    if(empty){
        this->cards = {};
        return;
    }
    this->cards = {
        //Yellow cards
        //--Number
        {CardType::CT_NUMBER,'0','y'},
        {CardType::CT_NUMBER,'1','y'},
        {CardType::CT_NUMBER,'1','y'},
        {CardType::CT_NUMBER,'2','y'},
        {CardType::CT_NUMBER,'2','y'},
        {CardType::CT_NUMBER,'3','y'},
        {CardType::CT_NUMBER,'3','y'},
        {CardType::CT_NUMBER,'4','y'},
        {CardType::CT_NUMBER,'4','y'},
        {CardType::CT_NUMBER,'5','y'},
        {CardType::CT_NUMBER,'5','y'},
        {CardType::CT_NUMBER,'6','y'},
        {CardType::CT_NUMBER,'6','y'},
        {CardType::CT_NUMBER,'7','y'},
        {CardType::CT_NUMBER,'7','y'},
        {CardType::CT_NUMBER,'8','y'},
        {CardType::CT_NUMBER,'8','y'},
        {CardType::CT_NUMBER,'9','y'},
        {CardType::CT_NUMBER,'9','y'},
        //--Action
        {CardType::CT_ACTION,'s','y'},
        {CardType::CT_ACTION,'s','y'},
        {CardType::CT_ACTION,'r','y'},
        {CardType::CT_ACTION,'r','y'},
        {CardType::CT_ACTION,char(2),'y'},
        {CardType::CT_ACTION,char(2),'y'},

        //Red cards
        //--Number
        {CardType::CT_NUMBER,'0','r'},
        {CardType::CT_NUMBER,'1','r'},
        {CardType::CT_NUMBER,'1','r'},
        {CardType::CT_NUMBER,'2','r'},
        {CardType::CT_NUMBER,'2','r'},
        {CardType::CT_NUMBER,'3','r'},
        {CardType::CT_NUMBER,'3','r'},
        {CardType::CT_NUMBER,'4','r'},
        {CardType::CT_NUMBER,'4','r'},
        {CardType::CT_NUMBER,'5','r'},
        {CardType::CT_NUMBER,'5','r'},
        {CardType::CT_NUMBER,'6','r'},
        {CardType::CT_NUMBER,'6','r'},
        {CardType::CT_NUMBER,'7','r'},
        {CardType::CT_NUMBER,'7','r'},
        {CardType::CT_NUMBER,'8','r'},
        {CardType::CT_NUMBER,'8','r'},
        {CardType::CT_NUMBER,'9','r'},
        {CardType::CT_NUMBER,'9','r'},
        //--Action
        {CardType::CT_ACTION,'s','r'},
        {CardType::CT_ACTION,'s','r'},
        {CardType::CT_ACTION,'r','r'},
        {CardType::CT_ACTION,'r','r'},
        {CardType::CT_ACTION,char(2),'r'},
        {CardType::CT_ACTION,char(2),'r'},

        //Green cards
        //--Number
        {CardType::CT_NUMBER,'0','g'},
        {CardType::CT_NUMBER,'1','g'},
        {CardType::CT_NUMBER,'1','g'},
        {CardType::CT_NUMBER,'2','g'},
        {CardType::CT_NUMBER,'2','g'},
        {CardType::CT_NUMBER,'3','g'},
        {CardType::CT_NUMBER,'3','g'},
        {CardType::CT_NUMBER,'4','g'},
        {CardType::CT_NUMBER,'4','g'},
        {CardType::CT_NUMBER,'5','g'},
        {CardType::CT_NUMBER,'5','g'},
        {CardType::CT_NUMBER,'6','g'},
        {CardType::CT_NUMBER,'6','g'},
        {CardType::CT_NUMBER,'7','g'},
        {CardType::CT_NUMBER,'7','g'},
        {CardType::CT_NUMBER,'8','g'},
        {CardType::CT_NUMBER,'8','g'},
        {CardType::CT_NUMBER,'9','g'},
        {CardType::CT_NUMBER,'9','g'},
        //--Action
        {CardType::CT_ACTION,'s','g'},
        {CardType::CT_ACTION,'s','g'},
        {CardType::CT_ACTION,'r','g'},
        {CardType::CT_ACTION,'r','g'},
        {CardType::CT_ACTION,char(2),'g'},
        {CardType::CT_ACTION,char(2),'g'},

        //Blue cards
        //--Number
        {CardType::CT_NUMBER,'0','b'},
        {CardType::CT_NUMBER,'1','b'},
        {CardType::CT_NUMBER,'1','b'},
        {CardType::CT_NUMBER,'2','b'},
        {CardType::CT_NUMBER,'2','b'},
        {CardType::CT_NUMBER,'3','b'},
        {CardType::CT_NUMBER,'3','b'},
        {CardType::CT_NUMBER,'4','b'},
        {CardType::CT_NUMBER,'4','b'},
        {CardType::CT_NUMBER,'5','b'},
        {CardType::CT_NUMBER,'5','b'},
        {CardType::CT_NUMBER,'6','b'},
        {CardType::CT_NUMBER,'6','b'},
        {CardType::CT_NUMBER,'7','b'},
        {CardType::CT_NUMBER,'7','b'},
        {CardType::CT_NUMBER,'8','b'},
        {CardType::CT_NUMBER,'8','b'},
        {CardType::CT_NUMBER,'9','b'},
        {CardType::CT_NUMBER,'9','b'},
        //--Action
        {CardType::CT_ACTION,'s','b'},
        {CardType::CT_ACTION,'s','b'},
        {CardType::CT_ACTION,'r','b'},
        {CardType::CT_ACTION,'r','b'},
        {CardType::CT_ACTION,char(2),'b'},
        {CardType::CT_ACTION,char(2),'b'},
        
        //Wild cards
        {CardType::CT_WILD,'w','n'},
        {CardType::CT_WILD,'w','n'},
        {CardType::CT_WILD,'w','n'},
        {CardType::CT_WILD,'w','n'},
        
        //Draw fours
        {CardType::CT_DRAW4,char(4),'n'},
        {CardType::CT_DRAW4,char(4),'n'},
        {CardType::CT_DRAW4,char(4),'n'},
        {CardType::CT_DRAW4,char(4),'n'}
    };
    LOG("Deck initialized\n");
    shuffle();
    for(Card& card : cards){
        printCard(card);
        std::cout << "\n";
    }
}

void Deck::shuffle(){
    std::vector<int> uniqueRandoms;
    for(int i=0;i<108;i++){
        int num = rand() % 108;
        bool prevFound = false;
        for(int j = 0;j<i;j++){
            if(num == uniqueRandoms[j]){
                prevFound = true;
            }
        }
        if(prevFound){
            i--;
        }else{
            uniqueRandoms.push_back(num);
        }
    }
    std::vector<Card> shuffledCards(108);
    for(int i=0;i<108;i++){
        shuffledCards[i] = cards[uniqueRandoms[i]];
    }
    cards = shuffledCards;
    LOG("Cards Shuffled\n");
}