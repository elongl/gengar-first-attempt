#include <boost/asio.hpp>
#include "client.h"

using boost::asio::ip::tcp;

Client::Client()
{
	boost::asio::io_context io_context;
	m_sock = tcp::socket(io_context);
}

void Client::Connect()
{
	tcp::resolver resolver(m_sock.get_executor());
	boost::asio::connect(m_sock, resolver.resolve("127.0.0.1", "10015"));
}

void Client::Send(std::string msg)
{
	boost::asio::write(m_sock, boost::asio::buffer(msg));
}

std::string Client::Receive()
{
	std::string msg;
	boost::asio::read(m_sock, boost::asio::buffer(msg));
	return msg;
}
