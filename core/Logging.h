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
void printCard(const Card& card);

#define LOG(x) std::cout << purple << "["<<APPNAME<<"]: " << x << white
#define LOG_WARN(x) std::cout << yellow << "["<<APPNAME<<"-WARN]: " << x << white
#define LOG_ERROR(x) std::cout << red << "["<<APPNAME<<"-ERROR]:" << __FILE__ << ":" << __FUNCTION__ <<"()"<<":"<< __LINE__ << ":\n" <<  x <<  white
#endif