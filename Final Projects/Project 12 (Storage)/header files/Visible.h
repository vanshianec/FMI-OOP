#ifndef _VISIBLE_H
#define _VISIBLE_H

class Visitor;

class Visible
{
public:
	virtual void accept(Visitor*) = 0;
};

#endif