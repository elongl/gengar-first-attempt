#pragma once
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::tcp;

class Client
{
private:
	boost::asio::io_service m_io;
	tcp::socket m_sock{ m_io };

public:
	void Connect();
	void Send(std::string&&);
	std::string Receive();
};
