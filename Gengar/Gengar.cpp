#include <iostream>
#include "machine.h"

int main()
{
	Machine machine;
	std::string buff;
	while (true)
	{
		std::getline(std::cin, buff);
		std::string output = machine.RunCommand(buff);
		std::cout << output << std::endl;
	}
}
