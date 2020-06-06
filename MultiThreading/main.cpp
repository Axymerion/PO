#include "Producer.hpp"
#include "Consumer.hpp"
#include <iostream>
#include <conio.h>

int main()
{
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

	while(true) //Obsluga konsoli
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
}