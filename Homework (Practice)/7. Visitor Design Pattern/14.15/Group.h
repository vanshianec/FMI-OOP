#ifndef _GROUP_H
#define _GROUP_H

#include <vector>
#include "Shape.h"

class Group : public Shape
{
public:
	Group(int x, int y, const char* text);
	Shape* clone();
	void accept(Visitor*);
	void addShape(Shape*);
	const size_t getNChildren() const;
	Shape* getChild(size_t i) const;
	~Group();

private:
	std::vector<Shape*> children;
};

#endif
