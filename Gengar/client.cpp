#include <iostream>
#include <boost/asio.hpp>
#include "client.h"

using boost::asio::ip::tcp;

Client::Client() : m_sock(m_io) {}

void Client::Connect()
{
	try
	{
		tcp::resolver resolver(m_io);
		boost::asio::connect(m_sock, resolver.resolve("127.0.0.1", "5555"));
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		exit(1);
	}
}

void Client::Send(std::string msg)
{
	try
	{
		boost::asio::write(m_sock, boost::asio::buffer(msg));
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		exit(1);
	}
}

std::string Client::Receive()
{
	std::string msg;
	try
	{
		boost::asio::read(m_sock, boost::asio::buffer(msg));
		return msg;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		exit(1);
	}
}
