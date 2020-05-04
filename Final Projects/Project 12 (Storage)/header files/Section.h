#ifndef __SECTION_H
#define __SECTION_H

class Section
{
private:
	size_t id;
	size_t currentItemsCount;
	size_t shelfsCount;
	size_t capacity;
public:
	Section();
	Section(size_t _id, size_t currentItemsCount, size_t _shelfsCount, size_t _capacity);
	const size_t getCapacity() const;
};

#endif
