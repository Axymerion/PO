#include "FileFactory.h"

IFile* FileFactory::OpenFile(std::string path, std::string mode)
{
	if (path.substr(path.size() - 3) == "bin")
	{
		return new BinaryFile(path, mode);
	}
	else if (path.substr(path.size() - 3) == "csv")
	{
		return new CsvFile(path, mode);
	}
}