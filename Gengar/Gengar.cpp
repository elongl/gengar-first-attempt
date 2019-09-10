#include <iostream>
#include <string>
#include "machine.hpp"
#include "logger.hpp"

int main()
{
	Machine machine;
	std::string input;
	Logger::info("This is a test.");
	Logger::warn("This is a test.");
	Logger::error("This is a test.");
	// while (true)
	// {
	// 	std::cout << "Command: ";
	// 	std::getline(std::cin, input);
	// 	std::string output = machine.RunCommand(input);
	// 	std::cout << output << std::endl;
	// }
}
