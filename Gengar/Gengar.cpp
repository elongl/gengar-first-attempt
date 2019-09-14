#include <iostream>
#include <boost/asio.hpp>
#include "client.h"

int main()
{
	Client client;
	client.Connect();
	client.Send("Hello World!");
}
