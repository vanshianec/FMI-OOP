#ifndef _MYLIST_H
#define _MYLIST_H

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

template <typename T>
struct box
{
	box();
	box(const T& _data, box<T>* _next);
	T data;
	box<T>* next;
};

template <typename T>
class LList
{
private:
	box<T>* first;
	void copyList(box<T>* otherFirst);

public:
	LList();
	LList(const LList<T>& other);
	LList<T>& operator=(const LList<T>& other);
	~LList();
	box<T>* boxAt(size_t index);
	T operator[](size_t index) const;
	T& operator[](size_t index);
	void push(const T& element);
	T pop();
	void insertAfter(size_t index, const T& element);
	void deleteAfter(size_t index);
	void print() const;
	int count(const T& element);
	void pushBack(const T& element);
	void operator+=(const T& element);
	void removeAll(const T& element);
	void append(const LList<T>& other);
	LList<T> concat(const LList<T>& other);
	void operator+=(const LList<T>& other);
	LList<T> operator+(const LList<T>& other);
	void reverse();
};

#endif 