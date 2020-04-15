#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
#include "FileError.h"

class BinaryFile
{
private:
	std::fstream file;
	std::string filePath;
	unsigned long length;
	std::fstream::openmode openMode;
public:
	BinaryFile(const std::string, const std::string);
	~BinaryFile();

	FileError Write(const std::vector<Point>&);
	FileError Read(std::vector<Point>&);
	FileError Read(Point&, const unsigned long);
};

