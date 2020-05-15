#ifndef _INVALIDPARAMETEREXCEPTION_H
#define _INVALIDPARAMETEREXCEPTION_H

#include<string>

class InvalidParameterException : public std::exception
{
private:
	std::string message;
public:
	InvalidParameterException(const std::string&);
	const char* what() const noexcept;
};

#endif