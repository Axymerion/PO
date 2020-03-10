#include "List.hpp"

List::List()
{
	this->first = nullptr;
	this->size = 0;
}

List::List(Point p)
{
	this->first = new Node;
	first->next = nullptr;
	first->p = p;
	this->size = 1;
}

List::~List() 
{
	for (size_t i = this->size; i >= 0; i--)
	{
		Pop(i);
	}
}

List::Node* List::Find(const size_t i)
{
	Node* temp = this->first;
	for (size_t j = i - 1; j < this->size - 1; j++)
	{
		temp = temp->next;
	}
	return temp;
}

void List::Pop(const size_t i)
{
	if (this->size > 1)
	{
		Node* temp1 = Find(i - 1);
		//TODO
		if(temp1->next != nullptr)
			{ }
		Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
	}
	else
	{
		delete this->first;
		this->first = nullptr;
	}
	this->size--;

}

void List::Push(const Point& p, const size_t i)
{
	if (this->size > 0) {
		Node* temp1 = Find(i - 1);
		Node* temp2 = new Node;
		temp2->next = temp1->next;
		temp2->p = p;
		temp1->next = temp2;
	}
	else
	{
		this->first = new Node{ p, nullptr };
	}
	this->size++;
}

List::Error List::Find(Point& out, const size_t i)
{
	if (i >= this->size)
	{
		return Error::INDEX_OUT_OF_BOUNDS;
	}
	else if(this->size == 0)
	{
		return Error::LIST_EMPTY;
	}

	out = Find(i)->p;
	return Error::SUCCESS;
}

List::Error List::PopBack()
{
	if (this->size == 0)
	{
		return Error::LIST_EMPTY;
	}

	Pop(this->size - 1);
	return Error::SUCCESS;
}

List::Error List::PushBack(const Point& p)
{
	Push(p, this->size);
	return Error::SUCCESS;
}

List::Error List::Insert(const Point& p, const size_t i)
{
	if (i > this->size || i < 0) 
	{
		return Error::INDEX_OUT_OF_BOUNDS;
	}

	Push(p, i);
	return Error::SUCCESS;
}