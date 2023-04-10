#include "card.hpp"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

Card::Card(unsigned int num, string type)
{
    this->num = num;
    this->type = type;
}
Card ::Card()
{
    this->num = 0;
    this->type = "";
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
        return 1;
    }
}
string Card::printCard(Card card)
{
    if (card.num == 11)
    {
        cout << "The card is: "
             << "Jack of" << card.type << endl;
    }
    else if (card.num == 12)
    {
        cout << "The card is: "
             << "Queen of" << card.type << endl;
    }
    else if (card.num == 13)
    {
        cout << "The card is: "
             << "King of" << card.type << endl;
    }
    else if (card.num == 14)
    {
        cout << "The card is: "
             << "Ace of" << card.type << endl;
    }
    else
    {
        cout << "The card is: " << card.num << "And type: " << card.type << endl;
    }
}