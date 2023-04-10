#pragma once
#include <string.h>
#include <string>
using namespace std;

class Card
{

    string type;      // Hearts, Spades, Diamonds or Clubs
    unsigned int num; // 2 to 14;

public:
    Card(unsigned int num, string type);
    Card();
    int compareTo(Card other);
    string printCard(Card other);
};
