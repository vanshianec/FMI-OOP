#ifndef _STRINGTRIMMER_CPP
#define _STRINGTRIMMER_CPP

#include "StringTrimmer.h"

/**
*   @brief Removes leading characters from a specified string.
*
*   @param str  The string from which the characters will be removed
*   @param chars  The characters to be removed from the string
*   @return     New string with the removed characters
*
*   Example:
*   @code
*     std::string s = "   leading";
*     StringTrimmer::ltrim(s);
*     std::cout << s << std::endl;
*     //outputs "leading" instead of "   leading"
*   @endcode
*/

std::string& StringTrimmer::ltrim(std::string& str, const std::string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

/**
*   @brief Removes trailing characters from a specified string.
*
*   @param str  The string from which the characters will be removed
*   @param chars  The characters to be removed from the string
*   @return     New string with the removed characters
*
*   Example:
*   @code
*     std::string s = "trailing   ";
*     StringTrimmer::rtrim(s);
*     std::cout << s << std::endl;
*     //outputs "trailing" instead of "trailing   "
*   @endcode
*/

std::string& StringTrimmer::rtrim(std::string& str, const std::string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

/**
*   @brief Removes trailing and leading characters from a specified string.
*
*   @param str  The string from which the characters will be removed
*   @param chars  The characters to be removed from the string
*   @return     New string with the removed characters
*
*   Example:
*   @code
*     std::string s = "   trim   ";
*     StringTrimmer::trim(s);
*     std::cout << s << std::endl;
*     //outputs "trim" instead of "   trim   "
*   @endcode
*/

std::string& StringTrimmer::trim(std::string& str)
{
	const std::string chars = "\t\n\v\f\r ";
	return ltrim(rtrim(str, chars), chars);
}

#endif