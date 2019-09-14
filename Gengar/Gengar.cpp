#include <iostream>
#include "client.h"

int main()
{
	Client client;
	client.Connect();
	client.Send("Hello World!");
}
