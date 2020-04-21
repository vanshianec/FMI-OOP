#ifndef _BLACKJACK_H
#define _BLACKJACK_H

#include "Card.cpp"
#include "Deck.cpp"
#include "Player.cpp"
#include "FileUtil.cpp"
#include "InputHandler.cpp"

class Blackjack
{
private:
	Player player;
	Deck deck;
	FileUtil fileManager;
	InputHandler inputHandler;

public:
	Blackjack();
	void start();

private:
	void choosePlayer();
	void createNewPlayer(const char* name);
	void chooseDeck();
	void createDeck(const char* input, const size_t len);
	void launchGame();
	void drawFirstCard();
	void updatePlayerStats();
	void executePlayerCommands();
	void executeHitCommand(Card* drawnCards, size_t& index, size_t& playerPoints);
	void simulateDealerTurn(size_t& dealerPoints);
	void printDrawnCards(Card* cards, const size_t len);
	void printWinner();
	void decideWinner(const size_t dealerPoints, const size_t playerPoints);
};

#endif 
