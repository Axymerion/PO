#include "List.hpp"

int main()
{
	List* l;
	while (true)
	{
		l = new List();
		for (int i = 0; i < 1000; i++)
		{
			Point p{ i, i, i };
			l->PushBack(p);
		}
		delete l;
	}
}