#ifndef _FILEIOEXCEPTION_H
#define _FILEIOEXCEPTION_H

#include <string>

class FileIOException : public std::exception
{
private:
	std::string message;
public:
	FileIOException(const std::string&);
	const char* what() const noexcept;
};

#endif