#ifndef _FILEIOEXCEPTION_H
#define _FILEIOEXCEPTION_H

#include <string>

/// @brief Custom made exception class for file inputs and outputs.

class FileIOException : public std::exception
{
private:
	/// @brief The message to be displayed from the exception.
	std::string message;
public:
	/// @brief Returns custom made exception for file inputs and outputs.
	FileIOException(const std::string&);
	/// @brief  The message the exception carries.
	const char* what() const noexcept;
};

#endif