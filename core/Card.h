#ifndef CARD_H
#define CARD_H
enum CardType{
    CT_DRAW4,
    CT_WILD,
    CT_NUMBER,
    CT_ACTION
};
class Card{
    public:
    CardType type;
    /*Identifiers:
    '0' to '9' = number cards
    's' = skip
    'r' = reverse
    (char)2 = draw 2
    'w' = wild
    (char)4 = draw 4
    */
   char identifier;
   /*Colors:
   'n' = none
   'y' = yellow
   'r' = red
   'g' = green
   'b' = blue
   */
  char color;
  Card(CardType type = CardType::CT_WILD,char identifier = 'w',char color = 'n');
};
#endif