#ifndef _BLACKJACK_CPP
#define _BLACKJACK_CPP

#include "Blackjack.h"

Blackjack::Blackjack() : deck(), player(), fileManager(), inputHandler() {}

void Blackjack::start()
{
	choosePlayer();
	chooseDeck();
	launchGame();
}

void Blackjack::choosePlayer()
{
	fileManager.printPlayers();

	std::cout << "Choose a player or enter a new player:\n";

	char name[50];
	inputHandler.readPlayerName(name);

	if (!fileManager.choosePlayer(player, name))
	{
		createNewPlayer(name);
	}

	std::cout << "You will play as " << name << " Choose the size of the deck:\n";
}

void Blackjack::createNewPlayer(const char* name)
{
	std::cout << "Enter age : \n";
	size_t age;
	inputHandler.readPlayerAge(age);
	player = Player(name, age);
}

void Blackjack::chooseDeck()
{
	char input[15];
	std::cin.getline(input, 15);
	size_t len = strlen(input);

	inputHandler.validateDeckInput(input, len);

	createDeck(input, len);
}

void Blackjack::createDeck(const char* input, const size_t len)
{
	size_t size = inputHandler.getDeckSize(input);
	char deckName[11];

	if (len - inputHandler.digitsCount(size) - 1 > 10)
	{
		std::cout << "Deck name is too long. Custom name will be created!\n";
		deckName[0] = '\0';
	}
	else
	{
		inputHandler.extractDeckName(input, deckName, len);
	}

	if (size == 52 && strlen(deckName) == 0)
	{
		deck = Deck();
	}
	else
	{
		deck = Deck(size, deckName);
	}
}

void Blackjack::launchGame()
{
	std::cout << "Start\n";

	drawFirstCard();
	executePlayerCommands();
	printWinner();
	updatePlayerStats();

	if (player.isNewPlayer())
	{
		fileManager.addPlayer(player);
	}
	else
	{
		fileManager.updatePlayerData(player);
	}
}

void Blackjack::drawFirstCard()
{
	Card card = deck.draw();
	player.addPoints(card.getPoints());
	std::cout << card;
	std::cout << "(Points: " << player.getCurrentPoints() << ")\n";
	std::cout << "Hit/Stand/Probability\n";
}

void Blackjack::updatePlayerStats()
{
	size_t gamesPlayed = player.getGamesPlayed();
	gamesPlayed++;
	player.setWinPercentage((double)player.getWins() / gamesPlayed);
	player.setGamesPlayed(gamesPlayed);
	player.setCurrentPoints(0);
}

void Blackjack::printWinner()
{
	size_t playerPoints = player.getCurrentPoints();

	if (playerPoints > 21)
	{
		std::cout << "You lose!\n";
	}
	else if (playerPoints == 21)
	{
		std::cout << "You win!\n'";
		player.setWins(player.getWins() + 1);
	}
	else
	{
		std::cout << "The dealer's draw: ";
		size_t dealerPoints = 0;
		simulateDealerTurn(dealerPoints);
		decideWinner(dealerPoints, playerPoints);
	}
}

void Blackjack::printDrawnCards(Card* cards, const size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		std::cout << cards[i] << " ";
	}
}

void Blackjack::executePlayerCommands()
{
	char command[12];
	std::cin >> command;
	size_t playerPoints = player.getCurrentPoints(), index = 0;
	Card drawnCards[10];

	while (strcmp(command, "Stand") != 0)
	{
		if (strcmp(command, "Hit") == 0)
		{
			executeHitCommand(drawnCards, index, playerPoints);

			if (playerPoints >= 21)
			{
				break;
			}
		}
		else if (strcmp(command, "Probability") == 0)
		{
			std::cout << deck.probabilityToWin(player.getCurrentPoints()) << std::endl;
		}
		else
		{
			std::cout << "Invalid comand\n";
		}
		std::cout << "Hit/Stand/Probability\n";
		std::cin >> command;
	}
}

void Blackjack::executeHitCommand(Card* drawnCards, size_t& index, size_t& playerPoints)
{
	Card card = deck.draw();
	drawnCards[index++] = card;
	if (card.getRank() == Rank::Ace && playerPoints >= 11)
	{
		player.addPoints(1);
	}
	else
	{
		player.addPoints(card.getPoints());
	}
	playerPoints = player.getCurrentPoints();
	printDrawnCards(drawnCards, index);
	std::cout << "(Points: " << playerPoints << ")\n";
}

void Blackjack::simulateDealerTurn(size_t& dealerPoints)
{
	size_t index = 0;
	Card drawnCards[11];
	Card card;

	while (dealerPoints <= 17)
	{
		card = deck.draw();
		drawnCards[index++] = card;
		if (card.getRank() == Rank::Ace && dealerPoints >= 11)
		{
			dealerPoints += 1;
		}
		else
		{
			dealerPoints += card.getPoints();
		}
	}

	printDrawnCards(drawnCards, index);
	std::cout << "(Points: " << dealerPoints << ")\n";
}

void Blackjack::decideWinner(const size_t dealerPoints, const size_t playerPoints)
{
	if (dealerPoints > 21 || playerPoints >= dealerPoints)
	{
		std::cout << "You win!\n";
		player.setWins(player.getWins() + 1);
	}
	else
	{
		std::cout << "You lose!\n";
	}
}

#endif