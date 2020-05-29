#ifndef _VISIBLE_H
#define _VISIBLE_H

class Visitor;

/// @brief Abstract class to be implemented by classes which need to be modified or processed.

class Visible
{
public:
	virtual void accept(Visitor*) = 0;
};

#endif