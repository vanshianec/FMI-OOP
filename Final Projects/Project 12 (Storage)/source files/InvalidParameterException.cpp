#ifndef _INVALIDPARAMETEREXCEPTION_CPP
#define _INVALIDPARAMETEREXCEPTION_CPP

#include "InvalidParameterException.h"

InvalidParameterException::InvalidParameterException(const std::string& error)
{
	message += error;
}
const char* InvalidParameterException::what() const noexcept
{
	return message.c_str();
}

#endif