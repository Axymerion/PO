#pragma once

struct Point 
{
	double x, y, z;
};

class List
{

public:
	enum Error { SUCCESS, INDEX_OUT_OF_BOUNDS, LIST_EMPTY };

	List();
	List(Point p);
	~List();

	Error PopBack();
	Error PushBack(const Point&);
	Error Find(Point&, const size_t);
	Error Insert(const Point&, const size_t);
	size_t Size();


private:
	struct Node 
	{
		Point p;
		Node* next;
	};

	Node* first;
	size_t size;

	Node* Find(const size_t);
	void Pop(const size_t);
	void Push(const Point&, const size_t);
};