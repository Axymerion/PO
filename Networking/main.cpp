#include "Server.hpp"
#include "Client.hpp"
#include "Frame.hpp"
#include <iostream>

int main()
{
	Server s(2137);
	Client c;

	s.Start();
	
	return c.RecvFile("wysylanie.txt", asio::ip::address_v4::from_string("127.0.0.1"), 2137);

}