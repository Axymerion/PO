#include "Client.hpp"

void Client::Echo(std::string text, asio::ip::address_v4 ip, const unsigned short port)
{
	Frame frame;
	strcpy_s(frame.data, text.data());

	asio::io_service ioService;
	asio::ip::tcp::socket socket(ioService);
	socket.connect(asio::ip::tcp::endpoint(ip, port));

	std::cout << "Sent echo request with: \'" << text << "\'" << std::endl;
	asio::write(socket, asio::buffer(&frame, sizeof(frame)));

	asio::read(socket, asio::buffer(&frame, sizeof(frame)));
	std::cout << "Echo: \'" << frame.data << "\'" << std::endl;
}