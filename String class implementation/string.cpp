#ifndef __STRING_CPP
#define __STRING_CPP

#include "string.h"

void String::copy(const char* otherData, const size_t otherLength)
{
	length = otherLength;
	data = new char[length + 1];
	strcpy_s(data, length + 1, otherData);
}

bool String::compare(const char* data, const char* otherData, bool (*cmp)(int)) const
{
	if (data == nullptr && otherData == nullptr)
	{
		return cmp(strcmp("", ""));
	}
	else if (data == nullptr)
	{
		return cmp(strcmp("", otherData));
	}
	else if (otherData == nullptr)
	{
		return cmp(strcmp(data, ""));
	}

	return cmp(strcmp(data, otherData));
}

String String::replaceOnce(const String& oldString, const String& newString, const int length, const int index) const
{
	if (index != -1)
	{
		size_t len = length - (oldString.length - newString.length);
		char* result = new char[len + 1];
		size_t i = 0;
		while (i < index)
		{
			result[i] = data[i];
			i++;
		}
		size_t newIndex = i + newString.length;
		size_t j = 0;
		while (i < newIndex)
		{
			result[i++] = newString.data[j++];
		}

		newIndex = newIndex - newString.length + oldString.length;
		while (newIndex < length)
		{
			result[i++] = data[newIndex++];
		}

		result[len] = '\0';
		String res(result);
		delete[]result;
		return res;
	}

	return *this;
}

String::String() : data(nullptr), length(0) {}

String::String(char c) : data(nullptr), length(0)
{
	if (c)
	{
		length = 1;
		data = new char[length + 1];
		data[0] = c;
		data[length] = '\0';
	}
}

String::String(const char* newData) : data(nullptr), length(0)
{
	if (newData != nullptr)
	{
		copy(newData, strlen(newData));
	}
}

String::String(const String& other) : data(nullptr), length(0)
{
	if (other.data != nullptr)
	{
		copy(other.data, other.length);
	}
}

String& String::operator = (const String& other)
{
	if (this != &other)
	{
		if (other.data != nullptr)
		{
			copy(other.data, other.length);
		}
		else if (data != nullptr)
		{
			data = nullptr;
			length = 0;
		}
	}

	return *this;
}

String::~String()
{
	delete[]data;
}

char* String::getData() const
{
	return data;
}

size_t String::getLength() const
{
	return length;
}

char String::operator[] (const int index) const
{
	validate(data, index, length);

	return data[index];
}

char& String::operator[](const int index)
{
	validate(data, index, length);

	return data[index];
}

String& String::operator += (const String& other)
{
	if (other.data != nullptr)
	{
		size_t len = other.length + length;
		char* newData = new char[len + 1];

		for (size_t i = 0; i < length; i++)
		{
			newData[i] = data[i];
		}

		for (size_t i = 0; i < other.length; i++)
		{
			newData[i + length] = other.data[i];
		}

		newData[len] = '\0';
		delete[]data;
		length = len;
		data = newData;
	}

	return *this;
}

String& String::operator += (const char* otherData)
{
	return *this += String(otherData);
}

String& String::operator += (const char c)
{
	return *this += String(c);
}

String String::concat(const String& other)
{
	return (String(*this) += other);
}

String String::concat(const char* otherData)
{
	return concat(String(otherData));
}

String String::concat(const char c)
{
	return concat(String(c));
}

bool String::isEmpty() const
{
	return length == 0;
}

bool String::contains(const String& other) const
{
	return indexOf(other) != -1;
}

bool String::contains(const char* otherData) const
{
	return indexOf(otherData) != -1;
}

bool String::contains(const char c) const
{
	return indexOf(c) != -1;
}

bool String::operator == (const String& other) const
{
	if (length != other.length)
	{
		return false;
	}

	for (size_t i = 0; i < length; i++)
	{
		if (data[i] != other.data[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator == (const char* otherData) const
{
	return (*this == String(otherData));
}

bool String::operator == (const char c) const
{
	return (*this == String(c));
}

bool String::equals(const String& other) const
{
	return (*this == other);
}

bool String::equals(const char* otherData) const
{
	return (*this == otherData);
}

bool String::equals(const char c) const
{
	return (*this == c);
}

bool String::equalsIgnoreCase(const String& other) const
{
	if (length != other.length)
	{
		return false;
	}

	for (size_t i = 0; i < length; i++)
	{
		char currentChar = data[i];
		char otherChar = other.data[i];

		if (currentChar != otherChar)
		{
			if (((currentChar >= 'a' && currentChar <= 'z') && (otherChar >= 'A' && otherChar <= 'Z')
				&& (currentChar - otherChar != 'a' - 'A'))
				|| ((currentChar >= 'A' && currentChar <= 'Z') && (otherChar >= 'a' && otherChar <= 'z')
					&& (currentChar - otherChar != 'A' - 'a')))
			{
				return false;
			}
		}
	}

	return true;
}

bool String::equalsIgnoreCase(const char* otherData) const
{
	return equalsIgnoreCase(String(otherData));
}

bool String::equalsIgnoreCase(const char c) const
{
	return equalsIgnoreCase(String(c));
}

bool String::operator != (const String& other) const
{
	return !(*this == other);
}

bool String::operator != (const char* otherData) const
{
	return !(*this == String(otherData));
}

bool String::operator != (const char c) const
{
	return !(*this == String(c));
}

bool String::operator < (const String& other) const
{
	return compare(data, other.data, less);
}

bool String::operator < (const char* otherData) const
{
	return compare(data, otherData, less);
}

bool String::operator < (const char c) const
{
	return (*this < String(c));
}

bool String::operator > (const String& other) const
{
	return compare(data, other.data, greater);
}

bool String::operator > (const char* otherData) const
{
	return compare(data, otherData, greater);
}

bool String::operator > (const char c) const
{
	return (*this > String(c));
}

bool String::operator <= (const String& other) const
{
	return compare(data, other.data, lessOrEqual);
}

bool String::operator <= (const char* otherData) const
{
	return compare(data, otherData, lessOrEqual);
}

bool String::operator <= (const char c) const
{
	return (*this <= String(c));
}

bool String::operator >= (const String& other) const
{
	return compare(data, other.data, greaterOrEqual);
}

bool String::operator >= (const char* otherData) const
{
	return compare(data, otherData, greaterOrEqual);
}

bool String::operator >= (const char c) const
{
	return (*this >= String(c));
}

String String::operator + (const String& other) const
{
	return String(*this) += other;
}

String String::operator + (const char* otherData) const
{
	return String(*this) += String(otherData);
}

String String::operator + (const char c) const
{
	return String(*this) += String(c);
}

String String::substring(int startIndex, int endIndex) const
{
	if (startIndex >= 0 && endIndex <= length || startIndex >= endIndex)
	{
		char* result = new char[endIndex - startIndex + 1];
		for (size_t i = startIndex; i < endIndex; i++)
		{
			result[i - startIndex] = data[i];
		}

		result[endIndex - startIndex] = '\0';
		String str(result);
		delete[]result;
		return str;
	}

	return "";
}

String String::substring(int startIndex) const
{
	return substring(startIndex, length);
}

bool String::startsWith(const String& prefix, const int offset) const
{

	return substring(offset, offset + prefix.length) == prefix;
}

bool String::startsWith(const String& other) const
{
	return startsWith(other, 0);
}

bool String::startsWith(const char* prefix, const int offset) const
{
	return startsWith(String(prefix), offset);
}

bool String::startsWith(const char* prefix) const
{
	return startsWith(String(prefix));
}

bool String::endsWith(const String& suffix, const int offset) const
{
	return substring(offset - suffix.length + 1, offset + 1) == suffix;
}

bool String::endsWith(const String& sufffix) const
{
	return endsWith(sufffix, length - 1);
}

bool String::endsWith(const char* suffix, const int offset) const
{
	return endsWith(String(suffix), offset);
}

bool String::endsWith(const char* suffix) const
{
	return endsWith(String(suffix));
}

int String::indexOf(const String& target, const int fromIndex) const
{
	if (fromIndex >= 0 && target.length)
	{
		for (size_t i = fromIndex; i < length; i++)
		{
			if (startsWith(target.data, i))
			{
				return i;
			}
		}
	}

	return -1;
}

int String::indexOf(const String& target) const
{
	return indexOf(target, 0);
}

int String::indexOf(const char* target, const int fromIndex) const
{
	return indexOf(String(target), fromIndex);
}

int String::indexOf(const char* target) const
{
	return indexOf(target, 0);
}

int String::indexOf(const char c, const int fromIndex) const
{
	if (fromIndex >= 0)
	{
		for (size_t i = fromIndex; i < length; i++)
		{
			if (data[i] == c)
			{
				return i;
			}
		}
	}

	return -1;
}

int String::indexOf(const char c) const
{
	return indexOf(c, 0);
}

int String::lastIndexOf(const String& target, const int fromIndex) const
{
	if (fromIndex >= 0 && fromIndex < length)
	{
		size_t targetLen = target.length;
		size_t index = fromIndex + 1;

		while (index >= targetLen && index >= 1)
		{
			if (data[index - 1] == target.data[target.length - 1] && substring(index - target.length, index) == target)
			{
				return index - target.length;
			}

			index--;
		}
	}

	return -1;
}

int String::lastIndexOf(const String& target) const
{
	return lastIndexOf(target, length - 1);
}

int String::lastIndexOf(const char* target, const int fromIndex) const
{
	return lastIndexOf(String(target), fromIndex);
}

int String::lastIndexOf(const char* target) const
{
	return lastIndexOf(target, length - 1);
}

int String::lastIndexOf(const char c, const int fromIndex) const
{
	if (fromIndex >= 0 && fromIndex < length)
	{
		for (int i = fromIndex; i >= 0; i--)
		{
			if (data[i] == c)
			{
				return i;
			}
		}
	}

	return -1;
}

int String::lastIndexOf(const char c) const
{
	return lastIndexOf(c, length - 1);
}

String String::toUpper() const
{
	String result = *this;

	for (int i = 0; i < length; i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			result.data[i] = result.data[i] - ('a' - 'A');
		}
	}
	return result;
}

String String::toLower() const
{
	String result = *this;

	for (int i = 0; i < length; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			result.data[i] = result.data[i] + ('a' - 'A');
		}
	}

	return result;
}

String String::replace(const String& oldString, const String& newString) const
{
	size_t len = 0;
	size_t occurences = 0;
	size_t index = indexOf(oldString, 0);

	while (index != -1)
	{
		occurences++;
		index = indexOf(oldString, index + oldString.length);
	}

	if (occurences == 0)
	{
		return *this;
	}

	len = length + (occurences * (newString.length - oldString.length));

	if (len <= 0)
	{
		return "";
	}

	char* result = new char[len + 1];
	size_t newIndex = 0;
	size_t i = 0;
	index = indexOf(oldString, 0);
	while (i < length)
	{
		if (i == index)
		{
			i += oldString.length;
			size_t j = 0;
			size_t newLen = newIndex + newString.length;
			while (newIndex < newLen)
			{
				result[newIndex++] = newString.data[j++];
			}

			index = indexOf(oldString, i);
		}
		else
		{
			result[newIndex++] = data[i++];
		}
	}

	result[len] = '\0';
	String res(result);
	delete[]result;
	return res;
}

String String::replace(const char* oldData, const char* newData) const
{
	return replace(String(oldData), String(newData));
}

String String::replace(const char oldChar, const char newChar) const
{
	return replace(String(oldChar), String(newChar));
}

String String::replaceFirst(const String& oldString, const String& newString) const
{
	size_t index = indexOf(oldString, 0);

	return replaceOnce(oldString, newString, length, index);
}

String String::replaceFirst(const char* oldData, const char* newData) const
{
	return replaceFirst(String(oldData), String(newData));
}

String String::replaceFirst(const char oldChar, const char newChar) const
{
	return replaceFirst(String(oldChar), String(newChar));
}

String String::replaceLast(const String& oldString, const String& newString) const
{
	size_t index = lastIndexOf(oldString);

	return replaceOnce(oldString, newString, length, index);
}

String String::replaceLast(const char* oldData, const char* newData) const
{
	return replaceLast(String(oldData), String(newData));
}

String String::replaceLast(const char oldChar, const char newChar) const
{
	return replaceLast(String(oldChar), String(newChar));
}

String String::trimStart() const
{
	int i = 0;
	while (data[i] == ' ' && i < length)
	{
		i++;
	}

	return (i > 0) ? substring(i) : *this;
}

String String::trimEnd() const
{
	int i = length - 1;
	while (data[i] == ' ' && i >= 0)
	{
		i--;
	}

	return (i != length - 1) ? substring(0, i + 1) : *this;
}

String String::trim() const
{
	String res = trimStart();
	res = res.trimEnd();
	return res;
}

bool less(const int cmp)
{
	return cmp < 0;
}

bool greater(const int cmp)
{
	return cmp > 0;
}

bool lessOrEqual(const int cmp)
{
	return cmp <= 0;
}

bool greaterOrEqual(const int cmp)
{
	return cmp >= 0;
}

bool validate(const char* data, const int index, const int length)
{
	if (index < 0 || index >= length)
	{
		throw "Index out of range";
	}
	else if (data == nullptr)
	{
		throw "String is empty";
	}
}

bool operator == (const char* data, const String& str)
{
	return (String(data) == str);
}

bool operator == (const char c, const String& str)
{
	return (String(c) == str);
}

bool operator != (const char* data, const String& str)
{
	return !(String(data) == str);
}

bool operator != (const char c, const String& str)
{
	return !(String(c) == str);
}

bool operator < (const char* data, const String& str)
{
	return (String(data) < str);
}

bool operator < (const char c, const String& str)
{
	return (String(c) < str);
}

bool operator > (const char* data, const String& str)
{
	return (String(data) > str);
}

bool operator > (const char c, const  String& str)
{
	return (String(c) > str);
}

bool operator <= (const char* data, const String& str)
{
	return (String(data) <= str);
}

bool operator <= (const char c, const String& str)
{
	return (String(c) <= str);
}

bool operator >= (const char* data, const String& str)
{
	return (String(data) >= str);
}

bool operator >= (const char c, const String& str)
{
	return (String(c) >= str);
}

String operator + (const char* otherData, const String& str)
{
	return String(otherData) += str;
}

String operator + (const char c, const String& str)
{
	return String(c) += str;
}

std::ostream& operator << (std::ostream& outputStream, const String& str)
{
	for (size_t i = 0; i < str.getLength(); i++)
	{
		outputStream << str[i];
	}

	return outputStream;
}

std::istream& operator >> (std::istream& inputStream, String& str)
{
	char* buffer = new char[1000];
	inputStream >> buffer;
	str = String(buffer);
	delete[]buffer;

	return inputStream;
}

#endif