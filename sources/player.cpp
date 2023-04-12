#include "player.hpp"
#include "card.hpp"
using namespace std;
Player ::Player(string name)
{
    cardstaken = 0;
    this->name = name;
    state = false;
}

int Player ::stacksize()
{
    return this->deck.size();
}

int Player ::cardesTaken()
{
    return cardstaken;
}
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
void Player::setDeck(std::vector<Card> &deck)
{
    this->deck = deck;
}
bool Player::getCurrentState()
{
    return state;
}
void Player::setState(bool playingstate)
{
    state = playingstate;
}
