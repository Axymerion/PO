#pragma once

template<typename T> class SmartPointer
{
	class ReferenceCounter
	{
		int counter;

	public:
		ReferenceCounter() : counter(0) {};
		ReferenceCounter(int param) : counter(param) {};

		void AddRef()
		{
			counter++;
		}

		void DelRef()
		{
			counter--;
		}

		int Count()
		{
			return counter;
		}
	};

	T* ptr;
	ReferenceCounter* counter;

public:
	SmartPointer() :ptr(nullptr), counter(new ReferenceCounter) {};
	SmartPointer(T* param) : ptr(param), counter(new ReferenceCounter(1)) {};
	SmartPointer(const SmartPointer<T> sm) : ptr(ptr), counter(counter)
	{
		counter->AddRef();
	}

	~SmartPointer()
	{
		counter->DelRef();
		if (counter->Count() == 0)
		{
			delete ptr;
			delete counter;
		}
	}

	SmartPointer<T> operator= (SmartPointer<T> param)
	{
		ptr = param.ptr;
		counter = param.counter;
		counter->AddRef();
	}

	T* operator-> ()
	{
		return ptr;
	}

	T* operator* ()
	{
		return ptr;
	}

	operator bool()
	{
		if (ptr == nullptr)
			return 0;
		return 1;
	}

	void Reset()
	{
		ptr = nullptr;
		delete counter;
		counter = new ReferenceCounter;
	}

	void Reset(T* ptr)
	{
		this->ptr = ptr;
		delete counter;
		counter = new ReferenceCounter(1);
	}

	void Swap(SmartPointer& param) 
	{
		T* tempP = param.ptr;
		param.ptr = this->ptr;
		this->ptr = tempP;

		ReferenceCounter* tempC = param.counter;
		param.counter = this->counter;
		this->counter = tempC;
	}
};

template<typename T, typename... Args> SmartPointer<T> make_smart_pointer(Args... args)
{
	return SmartPointer(new T(args...));
}