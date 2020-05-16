#include "FileFactory.h"
#include <iostream>

int main()
{
	IFile* test = FileFactory::OpenFile("test.csv", "r");
	//std::vector<Point> v;
	Point t;
	test->Read(t, 2);
}