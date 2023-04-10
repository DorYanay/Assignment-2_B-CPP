#include "player.hpp"
#include "card.hpp"
Player ::Player(string name)
{
    this->name = name;
    this->stack = 0;
};

Player ::Player()
{
    this->name = "";
    this->stack = 0;
};

int Player ::stacksize()
{
    return this->stack;
};

int Player ::cardesTaken()
{
    return 0;
};