#include "IntegratorPool.hpp"

IntegratorPool::IntegratorPool(size_t param)
{
	for (size_t i = 0; i < param; i++)
	{
		pool.push_back(new Integrator());
		pool.back()->Start();
	}
}

IntegratorPool::~IntegratorPool()
{
	for (size_t i = 0; i < pool.size(); i++)
	{
		pool[i]->Stop();
		delete pool[i];
	}
	pool.clear();
}

Integrator* IntegratorPool::GetInstance()
{
	while (true)
	{
		for (size_t i = 0; i < pool.size(); i++)
		{
			if(pool[i]->GetStatus() == Integrator::Status::IDLE)
			{
				return pool[i];
			}
		}
	}
}

size_t IntegratorPool::GetLoad()
{
	size_t load = 0;
	for (size_t i = 0; i < pool.size(); i++)
	{
		if (pool[i]->GetStatus() == Integrator::Status::WORKING)
		{
			load++;
		}
	}
	return load;
}