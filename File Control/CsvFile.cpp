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
	if (!(openMode & std::fstream::out))
	{
		return ACCESS_DENIED;
	}

	file.seekp(0, std::fstream::end);
	for (unsigned int i = 0; i < v.size(); i++)
	{
		file << v[i].x << ',' << v[i].y << ',' << v[i].z << std::endl;
	}
	length = file.tellp();
	return SUCCESS;
}

FileError CsvFile::Read(std::vector<Point>& v)
{
	if (!(openMode & std::fstream::in))
	{
		return ACCESS_DENIED;
	}

	file.seekg(0, std::fstream::beg);
	v.clear();

	while (!file.eof())
	{
		std::string temp;
		file >> temp;
		std::vector<std::string> tempV;
		tempV = Split(temp, ',');
		
		v[v.size()] = Point{std::stod(tempV[0]),
							std::stod(tempV[1]),
							std::stod(tempV[2])};
	}
	return SUCCESS;
}

FileError CsvFile::Read(Point& p, const unsigned long idx)
{
	//TODO
	return ACCESS_DENIED;
}