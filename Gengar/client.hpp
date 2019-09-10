#pragma once
#include <string>

class Client
{
public:
	void Connect();
	void Send();
	std::string Receive();
};
