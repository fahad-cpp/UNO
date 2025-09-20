#include "Logging.h"
#include <unordered_map>
#include <string>
#ifdef _WIN32
#include <Windows.h>
void setConsoleProperty(DWORD attribute){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle,attribute);
}
std::ostream& yellow(std::ostream& os){
    setConsoleProperty(FOREGROUND_RED | FOREGROUND_GREEN);
    return os;
}
std::ostream& red(std::ostream& os){
    setConsoleProperty(FOREGROUND_RED);
    return os;
}
std::ostream& green(std::ostream& os){
    setConsoleProperty(FOREGROUND_GREEN);
    return os;
}
std::ostream& blue(std::ostream& os){
    setConsoleProperty(FOREGROUND_BLUE);
    return os;
}
std::ostream& white(std::ostream& os){
    setConsoleProperty(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return os;
}
std::ostream& purple(std::ostream& os){
    setConsoleProperty(FOREGROUND_RED | FOREGROUND_BLUE);
    return os;
}
#else
std::ostream& yellow(std::ostream& os){
    return os << ":YELLOW";
}
std::ostream& red(std::ostream& os){
    return os << ":RED";
}
std::ostream& green(std::ostream& os){
    return os << ":GREEN";
}
std::ostream& blue(std::ostream& os){
    return os << ":BLUE";
}
std::ostream& white(std::ostream& os){
    return os << ":WHITE";
}
std::ostream& purple(std::ostream& os){
    return os << ":PURPLE";
}
#endif

void printCard(Card& card){
    std::unordered_map<char,std::string> identifierToName = {
        {'0',"Number 0"},
        {'1',"Number 1"},
        {'2',"Number 2"},
        {'3',"Number 3"},
        {'4',"Number 4"},
        {'5',"Number 5"},
        {'6',"Number 6"},
        {'7',"Number 7"},
        {'8',"Number 8"},
        {'9',"Number 9"},
        {'s',"Skip"},
        {'r',"Reverse"},
        {'w',"Wild"},
        {char(2),"Draw 2"},
        {char(4),"Draw 4"}
    };

    if(card.color == 'y'){
        std::cout << yellow << identifierToName[card.identifier] << white;
    }
    else if(card.color == 'r'){
        std::cout << red << identifierToName[card.identifier] << white;
    }
    else if(card.color == 'g'){
        std::cout << green << identifierToName[card.identifier] << white;
    }
    else if(card.color == 'b'){
        std::cout << blue << identifierToName[card.identifier] << white;
    }
    else{
        std::cout << identifierToName[card.identifier];
    }
}