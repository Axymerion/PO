#include "Producer.hpp"
#include "Consumer.hpp"
#include "IntegratorPool.hpp"
#include <iostream>
#include <conio.h>

int main()
{
	//Wyniki do zad 8:
		//100 punktow, 100 obiektow konwencjonalnie: 62ms
		//100 punktow, 100 obiektow IntegratorPool: 2ms

		//1000 punktow, 10 obiektow konwencjonalnie: 11ms
		//1000 punktow, 10 obiektow IntegratorPool: 1ms

		//1000000 punktow, 100 obiektow konwencjonalnie: 2974ms
		//1000000 punktow, 100 obiektow IntegratorPool : 2453ms


	Producer* pr[3];
	Consumer* cs[3];

	std::cout << "Starting threads..." << std::endl;
	for (int i = 0; i < 3; i++)
	{
		pr[i] = new Producer();
		pr[i]->Start();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));  //Czekamy, zeby watki mialy pewne rozsynchronizowanie miedzy soba, i inne seedy do randa
		cs[i] = new Consumer(pr[i]);
		cs[i]->Start();
	}
	std::cout << "Done!" << std::endl;

	while (true) //Obsluga konsoli
	{

		int buff = _getch();
		if (buff == 27) //ESCAPE
		{
			std::cout << "Stopping threads...";
			break;
		}
		else if (buff == 13) //ENTER
		{
			for (int i = 0; i < 3; i++)
			{
				std::cout << "Consumer " << i + 1 << ": " << cs[i]->GetAvg() << std::endl;
			}
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		pr[i]->Stop();
		cs[i]->Stop();
	}


	//Kod do testowania calek

	/*
	std::vector<double> a;
	for (int i = 0; i < 1000000; i++)
	{
		a.push_back(i);
	}


	IntegratorPool inPool(100);
	for (int i = 0; i < 100; i++)
	{
		inPool.GetInstance()->Count(a, 0.5);
	}
	while (inPool.GetLoad())
	{
	}




	Integrator* in[100];
	for (int i = 0; i < 100; i++)
	{
		in[i] = new Integrator();
		in[i]->Start();
		in[i]->Count(a, 0.5);
	}

	for (int i = 0; i < 100; i++)
	{
		while (in[i]->GetStatus() == Integrator::Status::WORKING)	std::this_thread::yield();
		in[i]->Stop();
		delete in[i];
	}
	*/
}