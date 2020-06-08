#pragma once
#include "IThread.hpp"
#include "Producer.hpp"

class Consumer : public IThread
{
	Producer* prodPtr;
	double avg;
	std::mutex avgMutex;

	void ThreadRoutine()
	{
		while (IsRunning())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
			std::list<double> temp = prodPtr->GetList();
			avgMutex.lock();
			avg = 0;
			for (double n : temp)
			{
				avg += n;
			}
			avg /= temp.size();
			avgMutex.unlock();
		}
	}

public:
	
	Consumer(Producer* param) : prodPtr(param), avg(0) {};

	double GetAvg()
	{
		avgMutex.lock();
		double d = avg;
		avgMutex.unlock();
		return d;
	}

};