#include "List.hpp"
using namespace std;

int main()
{
	List l1;
	List l2;
	l1.PushBack(Point{ 1, 2, 3 });
	l1.PushBack(Point{ 4, 5, 6 });
	l1.PushBack(Point{ 7, 8, 9 });
	
	l2.PushBack(Point{ -1, -2, -3 });

	cout << l1 + l2 << endl;
	cout << l2 * 3;
}