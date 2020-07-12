#pragma once
#include "asio.hpp"
#include "Frame.hpp"
#include "BinFile.h"
#include <string>
#include <iostream>


class Client
{
public:
	Client() {};
	~Client() {};
	void Echo(std::string, asio::ip::address_v4, const unsigned short);
	bool RecvFile(const std::string, const asio::ip::address_v4, const unsigned short);
	bool SendFile(const std::string, const asio::ip::address_v4, const unsigned short);
	void SendText(const std::string, const asio::ip::address_v4, const unsigned short);
};
