#pragma once
#include <string>

namespace bp = boost::process;
std::string quotify(std::string str) { return '"' + str + '"'; }

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

std::string GetGengarPath()
{
	char gengar_path[128];
	GetModuleFileNameA(nullptr, gengar_path, sizeof(gengar_path));
	return gengar_path;
}
