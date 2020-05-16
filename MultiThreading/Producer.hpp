#pragma once
#include "IThread.hpp"
#include <mutex>
#include <list>
#include <cstdlib>
#include <chrono>


class Producer : public IThread
{
	Producer()
	{
		srand(time(0));
	}

	std::list<double> list;
	
public:
	std::mutex listMutex;

	void ThreadRoutine()
	{
		listMutex.lock();
		list.push_back(rand());
		listMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	std::list<double> GetList()
	{
		std::list<double> temp;
		listMutex.lock();
		temp = list;
		listMutex.unlock();
		return temp;
	}
};