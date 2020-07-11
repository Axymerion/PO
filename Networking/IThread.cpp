#include "IThread.hpp"

IThread::IThread() : thrPtr(nullptr), thrState(STOPPED) {};

IThread::~IThread()
{
	Stop();
	//Join();
}

void IThread::Start()
{
	if (!thrPtr)
	{
		thrState = RUNNING;
		thrPtr = new std::thread(&IThread::ThreadRoutine, this);
	}
}

void IThread::Stop()
{
	if (thrPtr)
	{
		thrState = STOPPED;
		if (thrPtr->joinable())
			thrPtr->join();
		delete thrPtr;
		thrPtr = nullptr;
	}
}

void IThread::Join()
{
	if (thrPtr) 
	{
		if (thrPtr->joinable())
			thrPtr->join();
		thrState = STOPPED;
		delete thrPtr;
		thrPtr = nullptr;
	}
}

bool IThread::IsRunning()
{
	if (thrState == RUNNING)
		return 1;
	return 0;
}