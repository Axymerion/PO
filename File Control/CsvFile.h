#pragma once
#include "IFile.h"

class CsvFile : public IFile
{
private:
	void WriteLine(Point);
	std::vector<std::string> Split(std::string, char);
public:
	CsvFile(const std::string, const std::string);

	virtual FileError Write(const std::vector<Point>&);
	virtual FileError Read(std::vector<Point>&);
	virtual FileError Read(Point&, const unsigned long);
};