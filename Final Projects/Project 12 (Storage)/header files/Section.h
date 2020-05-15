#ifndef __SECTION_H
#define __SECTION_H

class Section
{
private:
	size_t itemsCount;
	size_t capacity;
public:
	Section();
	Section(const size_t _capacity);
	const size_t getCapacity() const;
	const size_t getItemsCount() const;
	void addItemsCount(const size_t count);
};

#endif
