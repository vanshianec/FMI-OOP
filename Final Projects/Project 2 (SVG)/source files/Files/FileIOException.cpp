#ifndef FILEIOEXCEPTION_CPP
#define FILEIOEXCEPTION_CPP

#include "FileIOException.h"

FileIOException::FileIOException(const std::string& type) :std::exception()
{
	message += type;
}

const char* FileIOException::what() const noexcept
{
	return message.c_str();
}

#endif