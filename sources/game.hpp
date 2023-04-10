#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#pragma once

class Game
{

    Player &player1;
    Player &player2;
    Card *deck;
    unsigned int turns;

public:
    Game(Player &player1, Player &player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};
namespace ariel
{
};