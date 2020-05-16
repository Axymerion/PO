#pragma once
#include "IThread.hpp"
#include "Producer.hpp"

class Consumer : public IThread
{
	Producer* prodPtr;
	double avg;
	std::mutex avgMutex;

public:
	
	Consumer(Producer* param) : prodPtr(param) {};

	void ThreadRoutine()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		std::list<double> temp = prodPtr->GetList();
		avgMutex.lock();
		avg = 0;
		for(double n : temp)
		{
			avg += n;
		}
		avg /= temp.size();
		avgMutex.unlock();
	}

	double GetAvg()
	{
		avgMutex.lock();
		double d = avg;
		avgMutex.unlock();
		return d;
	}

};