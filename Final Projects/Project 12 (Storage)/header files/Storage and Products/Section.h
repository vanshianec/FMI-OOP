#ifndef __SECTION_H
#define __SECTION_H

/// @brief Class that keeps track of the products count inside it.

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
	/// @brief Increases the current items count inside the section by the given amount.
	void addItemsCount(const size_t count);
};

#endif
