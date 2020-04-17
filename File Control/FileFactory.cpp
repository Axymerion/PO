#include "FileFactory.h"

IFile* FileFactory::OpenFile(std::string path, std::string mode)
{
	if (path[path.size() - 3] == 'b')
	{
		return new BinaryFile(path, mode);
	}
	else if (path[path.size() - 3] == 'c')
	{
		return new CsvFile(path, mode);
	}
}