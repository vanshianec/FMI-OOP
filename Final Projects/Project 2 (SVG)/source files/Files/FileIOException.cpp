#ifndef FILEIOEXCEPTION_CPP
#define FILEIOEXCEPTION_CPP

#include "FileIOException.h"

/**
*   @brief Returns custom made exception for file inputs and outputs.
*
*   @param type  The type of message received from the throw of the exception.
*
*	@return   FileIOException object.
*/

FileIOException::FileIOException(const std::string& type) :std::exception()
{
	message += type;
}

/**
*   @brief  The message the exception carries.
*
*	@return  The exception message.
*/

const char* FileIOException::what() const noexcept
{
	return message.c_str();
}

#endif