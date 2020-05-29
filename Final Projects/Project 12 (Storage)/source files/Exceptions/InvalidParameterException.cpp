#ifndef _INVALIDPARAMETEREXCEPTION_CPP
#define _INVALIDPARAMETEREXCEPTION_CPP

#include "InvalidParameterException.h"

/**
*   @brief Returns custom made exception for invalid object parameters.
*
*   @param error The type of message received from the throw of the exception.
*
*	@return InvalidParameterException object.
*/

InvalidParameterException::InvalidParameterException(const std::string& error)
{
	message += error;
}

/**
*   @brief  The message the exception carries.
*
*	@return  The exception message.
*/

const char* InvalidParameterException::what() const noexcept
{
	return message.c_str();
}

#endif