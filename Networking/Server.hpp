#pragma once
#include "IThread.hpp"
#include "asio.hpp"
#include "Frame.hpp"
#include <iostream>

class Server : public IThread
{
	unsigned short port;
public:
	Server(unsigned short);
	~Server();
	void ThreadRoutine();
};