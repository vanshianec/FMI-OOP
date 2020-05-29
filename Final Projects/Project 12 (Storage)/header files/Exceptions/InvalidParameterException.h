#ifndef _INVALIDPARAMETEREXCEPTION_H
#define _INVALIDPARAMETEREXCEPTION_H

#include<string>

/// @brief Custom made exception class for invalid object parameters.

class InvalidParameterException : public std::exception
{
private:
	/// @brief The message to be displayed from the exception.
	std::string message;
public:
	/// @brief Returns custom made exception for invalid object parameters.
	InvalidParameterException(const std::string&);
	/// @brief  The message the exception carries.
	const char* what() const noexcept;
};

#endif