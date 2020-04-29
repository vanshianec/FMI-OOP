#ifndef __FILEUTIL_H
#define __FILEUTIL_H

#include <string>

class FileUtil
{
private:
	std::string fileContent;
	std::string filePath;
	void readFile(std::ifstream& inFile);
	bool createNewFile(const std::string& path);
	std::string getFileName(const std::string& path) const;

public:
	std::string getFileContent() const;
	bool open(const std::string& path);
	bool save(const std::string& content);
	bool saveAs(const std::string& content, const std::string& path);
	void close() const;
};

#endif