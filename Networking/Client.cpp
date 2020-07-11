#include "Client.hpp"

void Client::Echo(std::string text, asio::ip::address_v4 ip, const unsigned short port)
{
	char frame[1024];
	strcpy_s(frame, text.data());

	asio::io_service ioService;
	asio::ip::tcp::socket socket(ioService);
	socket.connect(asio::ip::tcp::endpoint(ip, port));

	std::cout << "Sent echo request with: \'" << text << "\'" << std::endl;
	asio::write(socket, asio::buffer(&frame, strlen(frame)));

	asio::read(socket, asio::buffer(&frame, strlen(frame)));
	std::cout << "Echo: \'" << frame << "\'" << std::endl;
}