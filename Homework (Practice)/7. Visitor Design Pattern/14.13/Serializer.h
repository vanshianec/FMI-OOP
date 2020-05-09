#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include <fstream>
#include <string>
#include "Visitor.h"

class Serializer : public Visitor
{
private:
	std::ofstream out;
	std::string space;

public:
	Serializer();
	void processRectangle(Rectangle*);
	void processCircle(Circle*);
	void processGroup(Group*);
	~Serializer();
};

#endif