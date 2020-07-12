#include "Server.hpp"
#include "Frame.hpp"

Server::Server(unsigned short port) : port(port) {};

Server::~Server() {};

void session(asio::ip::tcp::socket socket) 
{
	try
	{
		while (true)
		{
			Frame frame;
			socket.read_some(frame);
			if (frame.type == FrameType::ECHO)
				asio::write(socket, asio::buffer(&frame, 1027));
		}
	}
	catch (std::exception& ex)
	{
		std::cerr << "Exception in " << ex.what() << '\n';
	}
};

void Server::ThreadRoutine()
{
	asio::io_service ioService;
	asio::ip::tcp::acceptor acceptor(ioService, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
	acceptor.listen(1024);
	while (IsRunning())
	{
		asio::ip::tcp::socket socket(ioService);
		acceptor.accept(socket);
		std::thread(session, std::move(socket)).detach();
		std::this_thread::yield();
	}
}
