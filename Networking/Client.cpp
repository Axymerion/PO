#include "Client.hpp"

void Client::Echo(std::string text, asio::ip::address_v4 ip, const unsigned short port)
{
	//Skladanie ramki
	Frame frame;
	strcpy_s(frame.data, text.data());
	frame.len = strlen(frame.data);
	frame.type = FrameType::ECHO;

	//Nawiazywanie polaczenia
	asio::io_service ioService;
	asio::ip::tcp::socket socket(ioService);
	socket.connect(asio::ip::tcp::endpoint(ip, port));

	//Wysylanie Echo
	std::cout << "Sent ECHO request with: \'" << text << "\'" << std::endl;
	asio::write(socket, asio::buffer(&frame, sizeof(frame)));

	//Odbieranie odpowiedzi
	asio::read(socket, asio::buffer(&frame, sizeof(frame)));
	std::cout << "Echo: \'" << frame.data << "\'" << std::endl;
}

bool Client::RecvFile(const std::string path, const asio::ip::address_v4 ip, const unsigned short port)
{
	//Nawiazywanie polaczenia
	asio::io_service ioService;
	asio::ip::tcp::socket socket(ioService);
	socket.connect(asio::ip::tcp::endpoint(ip, port));

	//Konstrukcja prosby o plik
	Frame frame;
	strcpy_s(frame.data, path.data());
	frame.len = strlen(frame.data);
	frame.type = FrameType::RECV_FILE;
	asio::write(socket, asio::buffer(&frame, sizeof(frame)));

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
	if (frame.type == FrameType::END_OF_FILE)
		return true;
	return false;
}

bool Client::SendFile(const std::string path, const asio::ip::address_v4 ip, const unsigned short port)
{
	//Nawiazywanie polaczenia
	asio::io_service ioService;
	asio::ip::tcp::socket socket(ioService);
	socket.connect(asio::ip::tcp::endpoint(ip, port));
	
	//Zapytanie o wyslanie pliku
	Frame frame;
	strcpy_s(frame.data, path.data());
	frame.len = strlen(frame.data);
	frame.type = FrameType::SEND_FILE;
	asio::write(socket, asio::buffer(&frame, sizeof(frame)));

	BinFile plik("wysylanie.txt", false);

	//Wysylanie fragmentow pliku
	while (frame.len = plik.Read((uint8_t*)frame.data, 1024))
	{
		frame.type = FrameType::FILE_DATA;
		asio::write(socket, asio::buffer(&frame, sizeof(frame)));
	}

	//Zakonczenie transmisji
	frame.type = FrameType::END_OF_FILE;
	asio::write(socket, asio::buffer(&frame, sizeof(frame)));

	return true;
}

void Client::SendText(const std::string text, const asio::ip::address_v4 ip, const unsigned short port)
{
	//Skladanie ramki
	Frame frame;
	strcpy_s(frame.data, text.data());
	frame.len = strlen(frame.data);
	frame.type = FrameType::TEXT;

	//Nawiazywanie polaczenia
	asio::io_service ioService;
	asio::ip::tcp::socket socket(ioService);
	socket.connect(asio::ip::tcp::endpoint(ip, port));

	//Wysylanie TEXT
	std::cout << "Sent TEXT request with: \'" << text << "\'" << std::endl;
	asio::write(socket, asio::buffer(&frame, sizeof(frame)));
}