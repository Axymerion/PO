#pragma once
#include <thread>

class IThread
{
public:
	enum Status { STOPPED, RUNNING };

	IThread();
	virtual ~IThread();
	bool IsRunning();
	void Start();
	void Stop();
	void Join();
	virtual void ThreadRoutine() = 0;


protected:
	Status thrState;
	std::thread* thrPtr;
};