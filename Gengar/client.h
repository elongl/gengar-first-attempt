#pragma once
#include <nlohmann/json.hpp>
#include <boost/asio.hpp>

using nlohmann::json;
using boost::asio::ip::tcp;

class Client
{
private:
	boost::asio::io_service m_io;
	tcp::socket m_sock{ m_io };

public:
	void Connect();
	void Send(std::string);
	json Receive();
};
