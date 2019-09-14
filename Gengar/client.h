#pragma once
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::tcp;

class Client
{
private:
	tcp::socket m_sock;

public:
	Client();
	void Connect();
	void Send(std::string);
	std::string Receive();
};
