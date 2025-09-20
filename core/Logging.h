#ifndef LOGGING_H
#define LOGGING_H
#define APPNAME "UNO"
#include "Card.h"
#include <iostream>
std::ostream& yellow(std::ostream&);
std::ostream& red(std::ostream&);
std::ostream& green(std::ostream&);
std::ostream& blue(std::ostream&);
std::ostream& white(std::ostream&);
std::ostream& purple(std::ostream&);

#define LOG(x) std::cout << purple << "["<<APPNAME<<"]: " << x << white
void printCard(Card& card);
#endif