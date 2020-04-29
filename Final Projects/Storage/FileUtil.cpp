#ifndef __FILEUTIL_CPP
#define __FILEUTIL_CPP

#include<iostream>
#include<fstream>

#include "FileUtil.h"
#include "Constants.h"

std::string FileUtil::getFileContent() const
{
	return fileContent;
}

void FileUtil::readFile(std::ifstream& inFile)
{
	std::string line;
	while (std::getline(inFile, line))
	{
		fileContent += line + '\n';
	}
}

bool FileUtil::createNewFile(const std::string& path)
{
	std::ofstream newFile(path, std::ios::out);

	if (!newFile)
	{
		return false;
	}

	newFile.close();
	return true;
}

std::string FileUtil::getFileName(const std::string& path) const
{
	//example path : C:/Users/Programming/Cpp/MyText.txt
	std::size_t found = path.find_last_of('/');
	if (found != std::string::npos)
	{
		return path.substr(found + 1);
	}

	return path;
}

bool FileUtil::open(const std::string& path)
{
	std::ifstream inFile(path);
	bool opened = true;

	if (inFile.is_open())
	{
		readFile(inFile);
	}
	else if (!createNewFile(path))
	{
		opened = false;
	}

	inFile.close();

	if (opened)
	{
		filePath = path;
		std::cout << FILE_OPENED_MESSAGE << getFileName(path) << std::endl;
		return true;
	}

	std::cout << FILE_ERROR_MESSAGE << std::endl;
	return false;
}

bool FileUtil::save(const std::string& content)
{
	return saveAs(content, filePath);
}

bool FileUtil::saveAs(const std::string& content, const std::string& path)
{
	std::ofstream outFile(path, std::ofstream::trunc);
	if (!outFile)
	{
		std::cout << FILE_ERROR_MESSAGE << std::endl;
		return false;
	}
	fileContent = content;
	filePath = path;
	outFile << fileContent;
	outFile.close();
	std::cout << FILE_SAVED_MESSAGE << getFileName(path) << std::endl;
	return true;
}

void FileUtil::close() const
{
	std::cout << FILE_CLOSED_MESSAGE << getFileName(filePath) << std::endl;
}

#endif