#include "FileFactory.h"
#include <iostream>

int main()
{
	IFile* test = FileFactory::OpenFile("test.csv", "r");
	std::vector<Point> v;
	test->Read(v);
}