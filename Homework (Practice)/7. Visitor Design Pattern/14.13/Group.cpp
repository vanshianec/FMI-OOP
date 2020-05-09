#ifndef _GROUP_CPP
#define _GROUP_CPP

#include "Group.h"
#include "Visitor.h"

Group::Group(int x, int y, const char* text) : Shape(x, y, text) {}

Shape* Group::clone()
{
	return new Group(*this);
}

void Group::accept(Visitor* visitor)
{
	visitor->processGroup(this);
}

void Group::addShape(Shape* shape)
{
	children.push_back(shape);
}

const size_t Group::getNChildren() const
{
	return children.size();
}

Shape* Group::getChild(size_t i) const
{
	return children[i];
}

Group::~Group()
{
	std::cout << "Group destructor " << std::endl;

	if (text != nullptr)
	{
		delete[]text;
	}

	for (Shape* shape : children)
	{
		delete shape;
	}
}


#endif