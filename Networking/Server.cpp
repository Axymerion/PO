#include "Server.hpp"
#include "Frame.hpp"

Server::Server(unsigned short port) : port(port) {};

Server::~Server() {};

void session(asio::ip::tcp::socket socket) 
{
	try
	{
		Frame frame;
		asio::read(socket, asio::buffer(&frame, sizeof(frame)));
		switch (frame.type)
		{
		case FrameType::ECHO:
			asio::write(socket, asio::buffer(&frame, sizeof(frame)));
			break;

		case FrameType::TEXT:
			std::cout << "(SERVER) TEXT: \'" << frame.data << "\'"<< std::endl;
			break;

		case FrameType::RECV_FILE:
		{
			char path[1024];
			strcpy_s(path, frame.len, frame.data);
			//Kontrola pliku
			BinFile plik(path, false);

			//Wysylanie framentow pliku
			while (frame.len = plik.Read((uint8_t*)frame.data, 1024))
			{
				frame.type = FrameType::FILE_DATA;
				asio::write(socket, asio::buffer(&frame, sizeof(frame)));
			}

			//Zakonczenie transmisji
			frame.type = FrameType::END_OF_FILE;
			asio::write(socket, asio::buffer(&frame, sizeof(frame)));
			break;
		}

		case FrameType::SEND_FILE:
		{
			//Kontrola pliku
			BinFile plik("odbior.txt", true);

			//Odebranie odpowiedzi na zapytanie
			asio::read(socket, asio::buffer(&frame, sizeof(frame)));
			while (frame.type == FrameType::FILE_DATA)
			{
				//Skladanie pliku 
				plik.Append((uint8_t*)frame.data, frame.len);
				asio::read(socket, asio::buffer(&frame, sizeof(frame)));

			}
			
			break;
		}
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

