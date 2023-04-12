#pragma once
#include <string.h>
#include <string>
using namespace std;

class Card
{
    string print;
    string type; // Hearts, Spades, Diamonds or Clubs
    int num;     // 2 to 14;

public:
    Card(int num, string type);
    Card();
    int compareTo(Card other);
    string printCard(Card other);
};
