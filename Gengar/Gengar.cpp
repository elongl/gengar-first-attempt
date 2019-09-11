#include <iostream>
#include <string>
#include "machine.hpp"
#include "logger.hpp"

int main()
{
	Machine machine;
	std::string input;
	while (true)
	{
		std::cout << "Command: ";
		std::getline(std::cin, input);
		std::string output = machine.RunCommand(input);
		std::cout << output << std::endl;
	}
}
