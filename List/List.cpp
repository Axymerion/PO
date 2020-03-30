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

List::List(const std::vector<Point>& inputVector)
{
	this->first = nullptr;
	this->size = 0;
	for (size_t i = 0; i < inputVector.size(); i++)
	{
		this->Push(inputVector[i], i);
	}
}

List::List(const List& inputList)
{
	this->first = nullptr;
	this->size = 0;
	Node* temp = inputList.first;

	for (size_t i = 0; i < inputList.size; i++)
	{
		this->Push(temp->p, this->size);
		temp = temp->next;
	}
}

List::~List() 
{
	while (first != nullptr) 
	{
		Node* temp = first;
		first = first->next;
		delete temp;
	}
	this->size = 0;
}

List::Node* List::Find(const size_t i)
{
	Node* temp = this->first;
	for (size_t j = 0; j < i; j++)
	{
		temp = temp->next;
	}
	return temp;
}

void List::Pop(const size_t i)
{
	if (this->size == 1)
	{
		delete this->first;
		this->first = nullptr;
	}
	else if (this->size > 1)
	{
		Node* temp1 = Find(i - 1);
		Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
	}
	else
	{
		Node* temp = Find(i - 1);
		delete temp->next;
		temp->next = nullptr;
	}
	this->size--;

}

void List::Push(const Point& p, const size_t i)
{
	if (this->size > 0) {
		Node* temp1 = Find(i - 1);
		Node* temp2 = new Node { p, temp1->next };
		temp1->next = temp2;
	}
	else
	{
		this->first = new Node{ p, nullptr };
	}
	this->size++;
}

void List::Push(const List& inputList, const size_t index)
{
	Node* temp = inputList.first;
	size_t size = inputList.size;
	for (size_t i = 0; i < size; i++)
	{
		this->Push(temp->p, index + i);
		temp = temp->next;
	}
}

void List::Multiply(const int multiplier)
{
	if (multiplier == 0)
	{
		this->~List();
		return;
	}
	else
	{
		List* temp = new List();
		*temp = *this;
		for (size_t i = 0; i < multiplier - 1; i++)
		{
			this->Push(*temp, this->size);
		}
	}
	delete temp;
}

List::Error List::Find(Point& out, const size_t i)
{
	if (i >= this->size)
	{
		return INDEX_OUT_OF_BOUNDS;
	}
	else if(this->size == 0)
	{
		return LIST_EMPTY;
	}

	out = Find(i)->p;
	return SUCCESS;
}

List::Error List::PopBack()
{
	if (this->size == 0)
	{
		return LIST_EMPTY;
	}

	Pop(this->size - 1);
	return SUCCESS;
}

List::Error List::PushBack(const Point& p)
{
	Push(p, this->size);
	return SUCCESS;
}

List::Error List::Insert(const Point& p, const size_t i)
{
	if (i > this->size || i < 0) 
	{
		return INDEX_OUT_OF_BOUNDS;
	}

	Push(p, i);
	return SUCCESS;
}

size_t List::Size()
{
	return this->size;
}

Point& List::operator[] (size_t index)
{
	Node* temp = Find(index);
	return temp->p;
}

List& List::operator=(const List& inputList)
{
	while (this->size > 0)
	{
		PopBack();
	}
	Node* temp1 = inputList.first;
	Node* temp2 = this->first = new Node{ temp1->p, nullptr };

	for (size_t i = 1; i < inputList.size; i++)
	{
		temp2->next = new Node{ temp1->p, nullptr };
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	this->size = inputList.size;
	return *this;
}

List& List::operator--(int)
{
	List *temp = new List(*this);
	this->PopBack();
	return *temp;
}

List& List::operator+=(const List& inputList)
{
	this->Push(inputList, size);
	return *this;
}

List& List::operator+(const List& inputList)
{
	List *temp = new List();
	*temp = *this;
	temp->Push(inputList, temp->size);
	return *temp;
}

List& List::operator*(const unsigned int scale)
{
	List* temp = new List();
	if (scale != 0)
	{
		*temp = *this;
		temp->Multiply(scale);
	}
	return *temp;
}

List& List::operator++(int)
{
	List *temp = new List(*this);
	this->~List();
	return *temp;
}

std::ostream& operator<<(std::ostream& os, const List& inputList)
{
	List::Node* temp = inputList.first;
	for (size_t i = 0; i < inputList.size; i++)
	{
		os << "x: " << temp->p.x << '\t' << "y: " << temp->p.y << '\t' << "z: " << temp->p.z << std::endl;
		temp = temp->next;
	}
	return os;
}
