#include <iostream>
#include <sstream>
#include <iomanip>
#include "logger.hpp"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

std::string gettime()
{
	time_t time = std::time(nullptr);
    tm now = *std::localtime(&time);
	std::ostringstream oss;
    oss << std::put_time(&now, "%d/%m/%Y %H:%M:%S");
    return oss.str();
}

void Logger::info(std::string msg)
{
	std::cout << gettime() << "INFO: " << msg << std::endl;
}
void Logger::warn(std::string msg)
{
	std::cout << gettime() << "WARNING: " << msg << std::endl;
}
void Logger::error(std::string msg)
{
	std::cout << gettime() << "ERROR: " << msg << std::endl;
}