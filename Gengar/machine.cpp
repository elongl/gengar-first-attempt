#include <iostream>
#include <boost/process.hpp>
#include "machine.h"

namespace bp = boost::process;
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

	bp::system("cmd /c " + cmd, bp::std_out > out_stream, bp::std_err > err_stream);
	ReadStream(out_stream, output);
	ReadStream(err_stream, output);
	return output;
}
