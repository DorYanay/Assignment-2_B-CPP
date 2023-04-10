#include <string>
#include <iostream>
#include "card.hpp"
#include <array>
#pragma once
using namespace std;

class Player
{
    string name;
    unsigned int stack;
    array<unsigned int, 3> stats{0, 0, 0};

public:
    Player(string name);
    Player();
    int stacksize();
    int cardesTaken();
};
