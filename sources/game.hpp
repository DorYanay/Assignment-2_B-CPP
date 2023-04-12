#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#pragma once

class Game
{
    int drawscnt;
    bool endturn;
    string str;
    int takes;
    Player &player1;
    Player &player2;
    Card *deck;
    int turns;
    std::vector<std::string> log;

public:
    Game(Player &player1, Player &player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

private:
    void shuffleDeck();
    void dealCards(Player &player1, Player &player2);
};
namespace ariel
{
};