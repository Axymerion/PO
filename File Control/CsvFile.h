#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include "point.h"
#include "FileError.h"

class CsvFile
{
private:
	std::fstream file;
	std::string filePath;
	unsigned long length;
	std::fstream::openmode openMode;
	void WriteLine(Point);
	std::vector<std::string> Split(std::string, char);
public:
	CsvFile(const std::string, const std::string);
	~CsvFile();

	FileError Write(const std::vector<Point>&);
	FileError Read(std::vector<Point>&);
	FileError Read(Point&, const unsigned long);
};