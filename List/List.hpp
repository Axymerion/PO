#include <vector>
#include <iostream>
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
	List(const std::vector<Point>&);
	List(const List&);
	~List();

	Error PopBack();
	Error PushBack(const Point&);
	Error Find(Point&, const size_t);
	Error Insert(const Point&, const size_t);
	size_t Size();

	List& operator=(const List&);
	List& operator--(int);
	List& operator+=(const List&);
	List& operator+(const List&);
	List& operator*(const unsigned int);
	List& operator++(int);
	Point& operator[](const size_t);
	friend std::ostream& operator <<(std::ostream&, const List&);


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
	void Push(const List&, const size_t);
	void Multiply(const int);
};

std::ostream& operator <<(std::ostream&, const List&);