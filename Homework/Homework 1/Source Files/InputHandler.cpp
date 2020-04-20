#ifndef _INPUTHANDLER_CPP
#define _INPUTHANDLER_CPP

#include<iostream>

#include "InputHandler.h"

void InputHandler::readPlayerName(char* name)
{
	std::cin.getline(name, 50);

	while (!isNameValid(name))
	{
		std::cout << "Invalid name please enter a name in the format : \"Firstname Lastname\"\n";
		std::cin.getline(name, 50);
	}
}

void InputHandler::readPlayerAge(size_t& age)
{
	std::cin >> age;

	while (age < 18 || age > 90)
	{
		std::cout << "You should be between 18 and 90 years old to play this game!\n";
		std::cin >> age;
	}

	std::cin.ignore();
}

void InputHandler::validateDeckInput(char* input, size_t& len)
{
	while (!isDeckInputValid(input, len))
	{
		std::cout << "Invalid input please enter the size of the deck(required) and the name of the deck(optional)\n";
		std::cin.getline(input, 15);
		len = strlen(input);
	}
}

size_t InputHandler::getDeckSize(const char* input)
{
	size_t size = 0;
	size_t index = 0;
	char num = input[index];
	while (num >= '0' && num <= '9')
	{
		size = size * 10 + (num - '0');
		num = input[++index];
	}

	return size;
}

void InputHandler::extractDeckName(const char* input, char* deckName, const size_t len)
{
	if (spacesCount(input, len) == 0)
	{
		deckName[0] = '\0';
		return;
	}

	size_t startIndex = 0;
	while (input[startIndex] != ' ')
	{
		startIndex++;
	}

	startIndex++;

	size_t i = startIndex;
	while (i < len)
	{
		deckName[i - startIndex] = input[i];
		i++;
	}

	deckName[i - startIndex] = '\0';
}

size_t InputHandler::digitsCount(size_t num)
{
	size_t count = 1;
	while (num > 9)
	{
		num /= 10;
	}

	return count;
}

bool InputHandler::isNameValid(const char* name)
{
	size_t len = strlen(name);
	if (len < 5 || spacesCount(name, len) != 1)
	{
		return false;
	}

	if ((name[0] < 'A' || name[0] > 'Z') || (name[1] < 'a' || name[1] > 'z'))
	{
		return false;
	}

	size_t index = 2;
	while (name[index] != ' ')
	{
		if (name[index] < 'a' || name[index] > 'z')
		{
			return false;
		}
		index++;
	}

	if ((name[index + 1] < 'A' || name[index + 1] > 'Z') || (name[index + 2] < 'a' || name[index + 2] > 'z'))
	{
		return false;
	}

	index = index + 3;

	while (index < len)
	{
		if (name[index] < 'a' || name[index] > 'z')
		{
			return false;
		}
		index++;
	}

	return true;
}

bool InputHandler::isDeckInputValid(const char* input, const size_t len)
{
	if (hasDigitsOnly(input, len))
	{
		return true;
	}

	if (len < 1 || (spacesCount(input, len) != 1))
	{
		return false;
	}

	if (input[0] < '1' || input[0] > '9')
	{
		return false;
	}

	size_t index = 1;

	while (input[index] != ' ')
	{
		if (input[index] < '0' || input[index] > '9')
		{
			return false;
		}
		index++;
	}
}

size_t InputHandler::spacesCount(const char* name, const size_t len)
{
	size_t count = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (name[i] == ' ')
		{
			count++;
		}
	}

	return count;
}

bool InputHandler::hasDigitsOnly(const char* input, const size_t len)
{
	size_t index = 0;
	while (index < len)
	{
		if (input[index] < '0' || input[index] > '9')
		{
			return false;
		}
		index++;
	}

	return true;
}

#endif