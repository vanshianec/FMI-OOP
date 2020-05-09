#ifndef _SPLITTER_H
#define _SPLITTER_H

#include "Visitor.h"

class Splitter : public Visitor
{
private:
	std::vector<Circle*> circles;
	std::vector<Rectangle*> rectangles;

public:
	void processRectangle(Rectangle*);
	void processCircle(Circle*);
	void processGroup(Group*);
	std::vector<Circle*> getCircles();
	std::vector<Rectangle*> getRectangles();
};

#endif
