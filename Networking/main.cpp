#include "Server.hpp"
#include "Client.hpp"

int main()
{
	Server s(2137);
	Client c;

	s.Start();
	std::string kek;
	while (true)
	{
		std::cin >> kek;
		c.Echo(kek, asio::ip::address_v4::from_string("127.0.0.1"), 2137);
	}
}