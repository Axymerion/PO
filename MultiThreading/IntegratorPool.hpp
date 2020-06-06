#include "Integrator.hpp"

class IntegratorPool
{
private:
	std::vector<Integrator*> pool;

public:
	IntegratorPool(size_t);
	~IntegratorPool();
	Integrator* GetInstance();
	size_t GetLoad();
};