#pragma once
#include "asio.hpp"
#include "Frame.hpp"
#include <string>
#include <iostream>


class Client
{
public:
	Client() {};
	~Client() {};
	void Echo(std::string, asio::ip::address_v4, const unsigned short);
};
