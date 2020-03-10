#include "List.hpp"

int main()
{
	List* l = new List();
	while (true)
	{
		for (int i = 0; i < 1000; i++)
		{
			Point p{ i, i, i };
			l->PushBack(p);
		}
		for (int i = 0; i < 1000; i++)
		{
			l->PopBack();
		}
	}
}