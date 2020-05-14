#ifndef _SERIALIZABLE_H
#define _SERIALIZABLE_H

class FileIO;

class Serializable
{
public:
	virtual void accept(FileIO* visitor) = 0;
};

#endif