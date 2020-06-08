#pragma once
#include <thread>

class IThread
{
public:
	IThread();
	virtual ~IThread();
	bool IsRunning();
	void Start();
	void Stop();
	void Join();
	virtual void ThreadRoutine() = 0;


private:
	enum Status { STOPPED, RUNNING };
	Status thrState;
	std::thread* thrPtr;
};