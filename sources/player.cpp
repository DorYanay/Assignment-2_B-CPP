#include "player.hpp"
#include "card.hpp"
using namespace std;
Player ::Player(string name)
{
    cardstaken = 0;
    this->name = name;
    this->stack = 0;
    state = false;
};

Player ::Player()
{
    cardstaken = 0;
    this->name = "Anonymous";
    this->stack = 0;
    state = false;
};

int Player ::stacksize()
{
    return this->deck.size();
};

int Player ::cardesTaken()
{
    return cardstaken;
};
Card Player::playCard()
{
    Card topCard = deck.front();
    deck.erase(deck.begin());
    return topCard;
}
void Player::addturnedCard()
{
    deck.erase(deck.begin());
}
std::string Player::getName() const
{
    return name;
}
void Player::takeCards(int turntake)
{
    cardstaken = cardstaken + turntake;
}
void Player::addCard(Card card)
{
    deck.push_back(card);
}
bool Player::getCurrentState()
{
    return state;
}
void Player::setState(bool playingstate)
{
    state = playingstate;
}
int Player::getWins()
{
    return wins;
}
int Player::getLoses()
{
    return loses;
}
int Player::getDraws()
{
    return draws;
}
void Player::addWin()
{
    wins++;
}
void Player::addLose()
{
    loses++;
}
void Player::addDraw()
{
    draws++;
}
