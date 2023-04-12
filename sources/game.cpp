#include "game.hpp"
using namespace std;

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2)
{
    if (player1.getCurrentState() || player2.getCurrentState())
    {
        throw std::runtime_error("one of the players are already in game.");
    }
    this->drawscnt = 0;
    this->endturn = true;
    this->takes = 0;
    this->str = "";
    this->turns = 0;
    shuffleDeck();
    dealCards(player1, player2);
    player1.setState(true);
    player2.setState(true);
}
void Game::shuffleDeck()
{
    const int numCards = 52;
    deck = new Card[numCards];
    int deckIndex = 0;
    for (int num = 2; num <= 14; num++)
    {
        deck[deckIndex++] = Card(num, "Hearts");
        deck[deckIndex++] = Card(num, "Spades");
        deck[deckIndex++] = Card(num, "Diamonds");
        deck[deckIndex++] = Card(num, "Clubs");
    }

    for (int i = 0; i < numCards; i++)
    {
        int randomIndex = rand() % numCards;
        Card temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}
void Game::dealCards(Player &player1, Player &player2)
{
    const int numCardsPerPlayer = 26;
    for (int i = 0; i < numCardsPerPlayer; i++)
    {
        player1.addCard(deck[i]);
        player2.addCard(deck[i + numCardsPerPlayer]);
    }
}
void Game::playTurn()
{
    if (&player1 == &player2)
    {
        throw std::invalid_argument("illegal, player can`t play against himself.");
    }
    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        cout << "there are no cards in players stacks." << endl;
    }
    if (this->endturn == true)
    {
        this->str = "";
    }
    this->turns = this->turns + 1;
    Card player1Card = player1.playCard();
    Card player2Card = player2.playCard();
    cout << "Turn " << turns << ": " << player1.getName() << "played: " << player1Card.printCard(player1Card) << ", " << player2.getName() << " played : " << player2Card.printCard(player1Card) << endl;
    this->str += player1.getName() + " played: " + player1Card.printCard(player1Card) + ", " + player2.getName() + " played: " + player2Card.printCard(player2Card) + ", ";
    this->takes = this->takes + 2;
    int compareResult = player1Card.compareTo(player2Card);
    if (compareResult == 1)
    {
        std::cout << player1.getName() << " Has won the turn" << std::endl;
        player1.takeCards(this->takes);
        this->str += player1.getName() + " Wins";
        log.push_back(this->str);
        player1.addWin();
        player2.addLose();
        this->endturn = true;
    }
    else if (compareResult == -1)
    {
        std::cout << player2.getName() << " Has won the turn" << std::endl;
        player2.takeCards(this->takes);
        this->str += player2.getName() + " Wins";
        log.push_back(this->str);
        player1.addLose();
        player2.addWin();
        this->endturn = true;
    }
    else
    {
        std::cout << "DRAW" << std::endl;
        this->drawscnt = this->drawscnt + 1;
        if (player1.stacksize() == 1 || player2.stacksize() == 1)
        {
            player1.takeCards((this->takes / 2) + 1);
            player2.takeCards((this->takes / 2) + 1);
            player1.setState(false);
            player2.setState(false);
            player1.addDraw();
            player2.addDraw();
            this->str += " Draw";
            log.push_back(this->str);
            return;
        }
        else if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            player1.takeCards((this->takes / 2));
            player2.takeCards((this->takes / 2));
            player1.addDraw();
            player2.addDraw();
            this->str += " Draw";
            log.push_back(this->str);
        }
        else
        {
            player1.addDraw();
            player2.addDraw();
            player1.addturnedCard();
            player2.addturnedCard();
            str += " Draw";
            log.push_back(str);
            playTurn();
        }
    }
}
void Game::printLastTurn()
{
    cout << log.back() << endl;
}
void Game::playAll()
{
    while (player1.stacksize() > 0 || player2.stacksize() > 0)
        playTurn();
}
void Game::printWiner()
{
    if (player1.stacksize() != 0 || player2.stacksize() != 0)
        cout << "The game not done yet." << endl;
    if (player1.cardesTaken() == player2.cardesTaken())
        cout << "TIE" << endl;
    else if (player1.cardesTaken() < player2.cardesTaken())
        cout << player2.getName() + " is the WINNER" << endl;
    else
        cout << player1.getName() + " is the WINNER" << endl;
}
void Game::printLog()
{
    for (const auto &entry : log)
    {
        cout << entry << endl;
    }
}
void Game ::printStats()
{
    cout << player1.getName() << "won : " << player1.getWins() << " WINRATE: " << (float)((player1.getWins()) / (this->turns)) << endl;
    cout << player1.getName() << "lost : " << player1.getLoses() << " WINRATE: " << (float)((player1.getLoses()) / (this->turns)) << endl;
    cout << player1.getName() << "cards won : " << player1.cardesTaken() << endl;

    cout << player2.getName() << "won : " << player2.getWins() << " WINRATE: " << (float)((player2.getWins()) / (this->turns)) << endl;
    cout << player2.getName() << "lost : " << player2.getLoses() << " WINRATE: " << (float)((player2.getLoses()) / (this->turns)) << endl;
    cout << player2.getName() << "cards won : " << player2.cardesTaken() << endl;

    cout << player1.getName() << "and" << player2.getName() << " drawed: " << this->drawscnt << "DRAWRATE: " << (float)((this->drawscnt) / (this->turns)) << endl;
}
