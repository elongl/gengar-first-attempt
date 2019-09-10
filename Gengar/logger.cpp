#include <chrono>
#include <ctime>
#include <iostream>
#include "logger.hpp"


std::chrono::system_clock clock;
void Logger::info(std::string msg)
{
	auto now = clock.to_time_t(clock.now());
	std::cout << std::ctime(&now) << "INFO: " << msg << std::endl;
}
void Logger::warn(std::string msg)
{
	auto now = clock.to_time_t(clock.now());
	std::cout << std::ctime(&now) << "WARNING: " << msg << std::endl;
}
void Logger::error(std::string msg)
{
	auto now = clock.to_time_t(clock.now());
	std::cout << std::ctime(&now) << "ERROR: " << msg << std::endl;
}