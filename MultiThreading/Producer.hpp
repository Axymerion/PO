#pragma once
#include "IThread.hpp"
#include <mutex>
#include <list>
#include <cstdlib>
#include <chrono>
#include <ctime>


class Producer : public IThread
{
	std::list<double> list;
	std::mutex listMutex;

	void ThreadRoutine()
	{
		srand(time(0));
		while (thrState == RUNNING)
		{
			listMutex.lock();
			list.push_back((double)rand() / RAND_MAX);
			listMutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
	
public:
	Producer(){}

	std::list<double> GetList()
	{
		std::list<double> temp;
		listMutex.lock();
		temp = list;
		listMutex.unlock();
		return temp;
	}
};