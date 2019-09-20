#include <iostream>
#include <boost/asio.hpp>
#include "client.h"

using boost::asio::ip::tcp;

void Client::Connect()
{
	tcp::resolver resolver(m_io);
	boost::asio::connect(m_sock, resolver.resolve("127.0.0.1", "5555"));
}

void Client::Send(std::string& data)
{
	boost::asio::write(m_sock, boost::asio::buffer(data));
}

std::string Client::Receive()
{
	std::string data;
	boost::asio::read(m_sock, boost::asio::buffer(data));
	return data;
}
