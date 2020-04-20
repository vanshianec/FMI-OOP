#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

class InputHandler
{
public:
	void readPlayerName(char* name);
	void readPlayerAge(size_t& age);
	void validateDeckInput(char* input, size_t& len);
	size_t getDeckSize(const char* input);
	void extractDeckName(const char* input, char* deckName, const size_t len);
	size_t digitsCount(size_t num);

private:
	bool isNameValid(const char* name);
	bool isDeckInputValid(const char* input, const size_t len);
	size_t spacesCount(const char* str, const size_t len);
	bool hasDigitsOnly(const char* input, const size_t len);
};

#endif 
