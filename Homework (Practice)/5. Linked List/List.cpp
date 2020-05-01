#ifndef _MYLIST_CPP
#define _MYLIST_CPP

// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include "List.h"

#include <cassert>
#include <iostream>

template<class T>
box<T>::box()
{
	data = NULL;
	next = nullptr;
}

template<class T>
box<T>::box(const T& _data, box<T>* _next)
{
	data = _data;
	next = _next;
}

template<class T>
void LList<T>::copyList(box<T>* otherFirst)
{
	clearData();

	if (otherFirst != nullptr)
	{
		first = new box<T>(otherFirst->data, nullptr);
		box<T>* temp = first;
		box<T>* otherTemp = otherFirst->next;

		while (otherTemp != nullptr)
		{
			temp->next = new box<T>(otherTemp->data, nullptr);
			temp = temp->next;
			otherTemp = otherTemp->next;
		}
	}
}

template<class T>
void LList<T>::clearData()
{
	box<T>* temp;
	while (first != nullptr)
	{
		temp = first;
		first = first->next;
		delete temp;
	}

	first = nullptr;
}

template<class T>
LList<T>::LList()
{
	first = nullptr;
}

template<class T>
LList<T>::LList(const LList<T>& other)
{
	first = nullptr;
	copyList(other.first);
}

template<class T>
LList<T>& LList<T>::operator=(const LList<T>& other)
{
	if (this != &other)
	{
		copyList(other.first);
	}

	return *this;
}

template<class T>
box<T>* LList<T>::boxAt(size_t index)
{
	assert(first != nullptr);

	box<T>* current = first;

	while (index > 0 && current != nullptr)
	{
		current = current->next;
		index--;
	}

	assert(current != nullptr);
	return current;
}

template<class T>
T LList<T>::operator[](size_t index) const
{
	return boxAt(index)->data;
}

template<class T>
T& LList<T>::operator[](size_t index)
{
	return boxAt(index)->data;
}

template<class T>
LList<T>::~LList()
{
	clearData();
}

template<class T>
void LList<T>::push(const T& element)
{
	/*
	box<T>* newElement = new box<T>(element, nullptr);
	newElement->next = first;
	first = newElement;
	*/
	first = new box<T>(element, first);
}

template<class T>
T LList<T>::pop()
{
	if (first != nullptr)
	{
		box<T>* temp = first;
		first = first->next;
		T data = temp->data;
		delete temp;
		return data;
	}

	return NULL;
}

template<class T>
void LList<T>::insertAfter(size_t index, const T& element)
{
	box<T>* current = boxAt(index);
	current->next->data = element;
}

template<class T>
void LList<T>::deleteAfter(size_t index)
{
	box<T>* current = boxAt(index);
	box<T>* temp = current->next;

	if (temp == nullptr)
	{
		return;
	}

	current->next = current->next->next;
	delete temp;
}

template<class T>
void LList<T>::print() const
{
	box<T>* temp = first;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << std::endl;
}

template<class T>
int LList<T>::count(const T& element)
{
	int count = 0;

	box<T>* current = first;

	while (current != nullptr)
	{
		if (current->data == element)
		{
			count++;
		}

		current = current->next;
	}

	return count;
}

template<class T>
void LList<T>::pushBack(const T& element)
{
	if (first == nullptr)
	{
		push(element);
		return;
	}

	box<T>* current = first;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = new box<T>(element, nullptr);
}

template<class T>
void LList<T>::operator+=(const T& element)
{
	pushBack(element);
}

template<class T>
void LList<T>::removeAll(const T& element)
{
	box<T>* prev = nullptr;
	box<T>* current = first;
	box<T>* temp = nullptr;

	while (current != nullptr)
	{
		if (current->data == element)
		{
			temp = current;
			current = current->next;

			if (prev != nullptr)
			{
				prev->next = current;
			}

			delete temp;
			continue;
		}

		if (prev == nullptr)
		{
			first = current;
		}
		prev = current;
		current = current->next;
	}
}

template<class T>
void LList<T>::append(const LList<T>& other)
{
	box<T>* current = other.first;
	while (current != nullptr)
	{
		pushBack(current->data);
		current = current->next;
	}
}

template<class T>
LList<T> LList<T>::concat(const LList<T>& other)
{
	LList<T> result = *this;
	box<T>* current = other.first;
	while (current != nullptr)
	{
		result.pushBack(current->data);
		current = current->next;
	}

	return result;
}

template<class T>
void LList<T>::operator+=(const LList<T>& other)
{
	append(other);
}

template<class T>
LList<T> LList<T>::operator+(const LList<T>& other)
{
	return concat(other);
}

template<class T>
void LList<T>::reverse()
{
	box<T>* prev = nullptr;
	box<T>* curr = first;
	box<T>* next = nullptr;

	while (curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	first = prev;
}

#endif
