#include "BinFile.h"



BinFile::BinFile(std::string filepath, bool overwrite)
{
	auto flags = std::fstream::in | std::fstream::binary;
	if (overwrite)
	{
		std::remove(filepath.c_str());
		flags |= std::fstream::out | std::fstream::app;
	}
	file.open(filepath, flags);
}


BinFile::~BinFile()
{
	file.close();
}

size_t BinFile::Read(uint8_t * buffer, size_t bytes)
{
	//check remaining stream size	
	size_t current = file.tellg();
	file.seekg(0, std::fstream::end);
	size_t size = (size_t)file.tellg() - current;
	file.seekg(current);
	//read bytes
	if (size < bytes) bytes = size;
	file.read((char *)buffer, bytes);
	return size_t(bytes);
}

void BinFile::Append(const uint8_t * buffer, size_t bytes)
{
	file.seekp(0, std::fstream::end);
	//add bytes to the end of file
	file.write((const char*)buffer, bytes);
}

bool BinFile::IsOpen()
{
	return file.is_open();
}
