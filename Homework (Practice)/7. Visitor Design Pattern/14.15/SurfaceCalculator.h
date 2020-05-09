#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "Visitor.h"

class SurfaceCalculator : public Visitor
{
private:
	double sum;
public:
	SurfaceCalculator();
	void processRectangle(Rectangle*);
	void processCircle(Circle*);
	void processGroup(Group*);
	double getSum();
};

#endif