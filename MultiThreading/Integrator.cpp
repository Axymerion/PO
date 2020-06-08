#include "Integrator.hpp"

Integrator::Integrator() : status(IDLE), step(0), result(0) {}

double Integrator::GetResult()
{
	resultMutex.lock();
	double temp = result;
	resultMutex.unlock();
	return temp;
}

Integrator::Status Integrator::GetStatus()
{
	statusMutex.lock();
	Integrator::Status temp = status;
	statusMutex.unlock();
	return temp;
}

void Integrator::Count(std::vector<double>& lparam, const double rparam)
{
	dataMutex.lock();
	data = lparam;
	step = rparam;
	SetStatus(WORKING);
	dataMutex.unlock();
}

void Integrator::SetStatus(Integrator::Status param)
{
	statusMutex.lock();
	status = param;
	statusMutex.unlock();
}

void Integrator::ThreadRoutine()
{
	while (IsRunning())
	{
		if (GetStatus() == WORKING)
		{
			dataMutex.lock();
			resultMutex.lock();
			result = 0;
			for (int i = 0; i < data.size(); i++)
			{
				result += data[i] * step;
			}
			resultMutex.unlock();
			dataMutex.unlock();
			SetStatus(IDLE);
		}
		else
		{
			std::this_thread::yield();
		}
	}
}