#include <iostream>
#include <boost/process.hpp>
#include "machine.h"

namespace bp = boost::process;
void ReadStream(bp::ipstream& stream, std::string& output)
{
	std::string buff;
	while (std::getline(stream, buff))
	{
		buff.pop_back();
		buff.push_back('\n');
		output.append(buff);
	}
}

std::string Machine::RunShellCommand(std::string cmd)
{
	std::string data;
	bp::ipstream out_stream, err_stream;

	bp::system("cmd /c " + cmd, bp::std_out > out_stream, bp::std_err > err_stream);
	ReadStream(out_stream, data);
	ReadStream(err_stream, data);
	return data;
}
