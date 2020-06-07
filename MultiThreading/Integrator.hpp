#include "IThread.hpp"
#include <vector>
#include <mutex>

class Integrator : public IThread
{
public:
	Integrator();
	enum Status {IDLE, WORKING};
	void Count(std::vector<double>&, const double);
	Status GetStatus();
	double GetResult();

private:
	double step;
	double result;
	std::vector<double> data;
	Status status;
	std::mutex dataMutex;
	std::mutex statusMutex;
	std::mutex resultMutex;
	void SetStatus(Status);
	void ThreadRoutine();
};
