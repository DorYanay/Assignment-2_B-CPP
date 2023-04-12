#include "card.hpp"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

Card::Card(int num, string type)
{

    this->num = num;
    this->type = type;
}
int Card ::compareTo(Card other)
{
    if (this->num == 14 && other.num == 2)
    {
        return -1;
    }
    else if (this->num == 2 && other.num == 14)
    {
        return 1;
    }
    else if (this->num > other.num)
    {
        return 1;
    }
    else if (this->num < other.num)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
string Card::printCard()
{
    if (num == 11)
    {
        return "The card is: Jack of " + type;
    }
    else if (num == 12)
    {
        return "The card is: Queen of " + type;
    }
    else if (num == 13)
    {
        return "The card is: King of " + type;
    }
    else if (num == 14)
    {
        return "The card is: Ace of " + type;
    }
    else
    {
        return "The card is: " + to_string(num) + " of " + type;
    }
}