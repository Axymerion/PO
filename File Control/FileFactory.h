#pragma once
#include "CsvFile.h"
#include "BinaryFile.h"

class FileFactory
{
public:
	static IFile* OpenFile(std::string, std::string);
};