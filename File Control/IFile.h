#pragma once
#include <sstream>
#include <fstream>
#include <vector>
#include "FileError.h"
#include "Point.h"


class IFile 
{
protected:
	std::fstream file;
	std::string filePath;
	unsigned long length;
	std::fstream::openmode openMode;

public:
	virtual ~IFile()
	{
		file.close();
	}

	virtual FileError Write(const std::vector<Point>&) = 0;
	virtual FileError Read(std::vector<Point>&) = 0;
	virtual FileError Read(Point&, const unsigned long) = 0;
};