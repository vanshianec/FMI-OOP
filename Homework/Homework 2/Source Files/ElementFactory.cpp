#ifndef _ELEMENTFACTORY_CPP
#define _ELEMENTFACTORY_CPP

#include "ElementFactory.h"
#include "Gold.h"
#include "Stone.h"
#include "Energy.h"
#include "Spirit.h"

Element* ElementFactory::createElement(const std::string& type, const size_t amount)
{
	if (type == "Philosopher's Stone")
	{
		return new PhilosophersStone(amount);
	}
	else if (type == "Earth")
	{
		return new Earth(amount);
	}
	else if (type == "Fire")
	{
		return new Fire(amount);
	}
	else if (type == "Water")
	{
		return new Water(amount);
	}
	else if (type == "Air")
	{
		return new Air(amount);
	}
	else if (type == "Metal")
	{
		return new Metal(amount);
	}
	else if (type == "Stone")
	{
		return new Stone(amount);
	}
	else if (type == "Energy")
	{
		return new Energy(amount);
	}
	else if (type == "Spirit")
	{
		return new Spirit(amount);
	}
	else if (type == "Gold")
	{
		return new Gold(amount);
	}

	return nullptr;
}

#endif