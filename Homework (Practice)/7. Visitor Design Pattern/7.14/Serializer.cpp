#ifndef _SERIALIZER_CPP
#define _SERIALIZER_CPP

#include "Serializer.h"

Serializer::Serializer()
{
	out.open("test.txt");
	space = "";
}

void Serializer::processCircle(Circle* circle)
{
	out << space << "circle " << circle->getX() << " " << circle->getY()
		<< " " << circle->getRadius() << std::endl;
}

void Serializer::processRectangle(Rectangle* rect)
{
	out << space << "rectangle " << rect->getX() << " " << rect->getY()
		<< " " << rect->getHeight() << " " << rect->getWidth() << std::endl;
}

void Serializer::processGroup(Group* group)
{
	size_t size = group->getNChildren();
	out << space << "group " << group->getX() << " " << group->getY() << " " << size << std::endl;	
	
	space += "\t";

	for (size_t i = 0; i < size; i++)
	{
		group->getChild(i)->accept(this);
	}

	space.replace(space.find_last_of("\t"), space.length(), "");
}

Serializer::~Serializer()
{
	out.close();
}

#endif