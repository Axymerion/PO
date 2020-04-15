#include "CsvFile.h"

CsvFile::CsvFile(const std::string filePath, const std::string mode) : filePath(filePath)
{
	if (mode.find("r") != std::string::npos) openMode |= std::fstream::in;
	if (mode.find("w") != std::string::npos) openMode |= std::fstream::out;
	if (mode.find("a") != std::string::npos) openMode |= std::fstream::app;
	if (mode.find("t") != std::string::npos) openMode |= std::fstream::trunc;
	if (mode.find("e") != std::string::npos) openMode |= std::fstream::ate;

	file.open(filePath, openMode);
	file.seekg(0, std::fstream::end);
	length = file.tellg() / sizeof( char );
	file.seekg(0, std::fstream::beg);
}

CsvFile::~CsvFile()
{
	file.close();
}

void CsvFile::WriteLine(Point p)
{
	file.seekp(0, std::fstream::end);
	file << p.x << ',' << p.y << ',' << p.z << std::endl;
}

std::vector<std::string> CsvFile::Split(std::string str, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string item;
	while (getline(ss, item, delim)) {
		result.push_back(item);
	}
	return result;
}

FileError CsvFile::Write(const std::vector<Point> &v)
{
	file.seekp(0, std::fstream::end);
	for (int i = 0; i < v.size(); i++)
	{
		file << v[i].x << ',' << v[i].y << ',' << v[i].z << std::endl;
	}
	length = file.tellp();
}

FileError CsvFile::Read(std::vector<Point>& v)
{
	//Tu sie konczy to co dziala xD
	file.seekg(0, std::fstream::beg);
	while (!file.eof)
	{
		std::string temp;
		file >> temp;
		std::vector<std::string> tempV;
		tempV = Split(temp, ',');
		
	}
}

FileError CsvFile::Read