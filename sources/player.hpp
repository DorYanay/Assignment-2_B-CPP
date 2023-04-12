#include <string>
#include <iostream>
#include "card.hpp"
#include <vector>
#pragma once

class Player
{
    int wins;
    int loses;
    int draws;
    std::string name;
    int cardstaken;
    bool state;
    std::vector<Card> deck;

public:
    Player(std::string name);
    int stacksize();
    int cardesTaken();
    Card playCard();
    void addturnedCard();
    void setDeck(std::vector<Card> &deck);
    std::string getName() const;
    void takeCards(int);
    bool getCurrentState();
    void setState(bool);
    int getWins();
    int getDraws();
    int getLoses();
};
