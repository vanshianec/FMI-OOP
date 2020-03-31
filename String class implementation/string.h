#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#include <cstring>

class String
{
private:
	char* data;
	size_t length;
	void copy(const char* otherData, const size_t otherLength);
	bool compare(const char* data, const char* otherData, bool (*cmp)(int)) const;
	String replaceOnce(const String& oldString, const String& newString, const int length, const int index) const;

public:
	String();
	String(char c);
	String(const char* newData);
	String(const String& other);
	String& operator = (const String& other);
	~String();
	char* getData() const;
	size_t getLength() const;
	char operator [] (const int index) const;
	char& operator[](const int index);
	String& operator += (const String& other);
	String& operator += (const char* otherData);
	String& operator += (const char c);
	String concat(const String& other);
	String concat(const char* otherData);
	String concat(const char c);
	bool isEmpty() const;
	bool contains(const String& other) const;
	bool contains(const char* otherData) const;
	bool contains(const char c) const;
	bool operator == (const String& other) const;
	bool operator == (const char* otherData) const;
	bool operator == (const char c) const;
	bool equals(const String& other) const;
	bool equals(const char* otherData) const;
	bool equals(const char c) const;
	bool equalsIgnoreCase(const String& other) const;
	bool equalsIgnoreCase(const char* otherData) const;
	bool equalsIgnoreCase(const char c) const;
	bool operator != (const String& other) const;
	bool operator != (const char* otherData) const;
	bool operator != (const char c) const;
	bool operator < (const String& other) const;
	bool operator < (const char* otherData) const;
	bool operator < (const char c) const;
	bool operator > (const String& other) const;
	bool operator > (const char* otherData) const;
	bool operator > (const char c) const;
	bool operator <= (const String& other) const;
	bool operator <= (const char* otherData) const;
	bool operator <= (const char c) const;
	bool operator >= (const String& other) const;
	bool operator >= (const char* otherData) const;
	bool operator >= (const char c) const;
	String operator + (const String& other) const;
	String operator + (const char* otherData) const;
	String operator + (const char c) const;
	String substring(int startIndex) const;
	String substring(int startIndex, int endIndex) const;
	bool startsWith(const String& prefix, const int offset) const;
	bool startsWith(const String& prefix) const;
	bool startsWith(const char* prefix, const int offset) const;
	bool startsWith(const char* prefix)  const;
	bool endsWith(const String& suffix, const int offset) const;
	bool endsWith(const String& suffix) const;
	bool endsWith(const char* suffix, const int offset) const;
	bool endsWith(const char* suffix) const;
	int indexOf(const String& target, const int fromIndex) const;
	int indexOf(const String& target) const;
	int indexOf(const char* target, const int fromIndex) const;
	int indexOf(const char* target) const;
	int indexOf(const char c, const int fromIndex) const;
	int indexOf(const char c) const;
	int lastIndexOf(const String& target, const int fromIndex) const;
	int lastIndexOf(const String& target) const;
	int lastIndexOf(const char* target, const int fromIndex) const;
	int lastIndexOf(const char* target) const;
	int lastIndexOf(const char c, const int fromIndex) const;
	int lastIndexOf(const char c) const;
	String toUpper() const;
	String toLower() const;
	String replace(const String& oldString, const String& newString) const;
	String replace(const char* oldData, const char* newData) const;
	String replace(const char oldChar, const char newChar) const;
	String replaceFirst(const String& oldString, const String& newString) const;
	String replaceFirst(const char* oldData, const char* newData) const;
	String replaceFirst(const char oldChar, const char newChar) const;
	String replaceLast(const String& oldString, const String& newString) const;
	String replaceLast(const char* oldData, const char* newData) const;
	String replaceLast(const char oldChar, const char newChar) const;
	String trimStart() const;
	String trimEnd() const;
	String trim() const;
};

bool less(const int cmp);
bool greater(const int cmp);
bool lessOrEqual(const int cmp);
bool greaterOrEqual(const int cmp);
bool validate(const char* data, const int index, const int length);
bool operator == (const char* data, const String& str);
bool operator == (const char c, const String& str);
bool operator != (const char* data, const String& str);
bool operator != (const char c, const String& str);
bool operator < (const char* data, const String& str);
bool operator < (const char c, const String& str);
bool operator > (const char* data, const String& str);
bool operator > (const char c, const String& str);
bool operator <= (const char* data, const String& str);
bool operator <= (const char c, const String& str);
bool operator >= (const char* data, const String& str);
bool operator >= (const char c, const String& str);
String operator + (const char* data, const String& str);
String operator + (const char c, const String& str);
std::ostream& operator << (std::ostream& outputStream, const String& str);
std::istream& operator >> (std::istream& inputStream, String& str);

#endif