#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#pragma once

class Game
{
    size_t drawscnt;
    bool endturn;
    string str;
    int takes;
    Player &player1;
    Player &player2;
    size_t turns;
    std::vector<std::string> log;
    size_t w1;
    size_t w2;

public:
    Game(Player &player1, Player &player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

private:
    void createDeckAndDealCards(Player &player1, Player &player2);
};
namespace ariel
{
};