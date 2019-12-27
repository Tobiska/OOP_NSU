#include "Dump.h"
#include "BlockMaker.h"

static BlockMaker<Dump> dumpMâaker("dump");

std::string Dump::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count != 1) {
		throw MyException("EXEPRION: invalid readblock and writeblock count","Dump.cpp");
	}
	if (data.empty() || text.empty() || data.size() > 1)
	{
		throw MyException("EXCEPTION: invalid arguments for dump","Dump.cpp");
	}
	std::ofstream out;
	out.open(data[0]);
	if (!out.is_open())
	{
		throw MyException("EXCEPTION: can't open file","Dump.cpp");
	}
	out << text;

	out.close();
	return text;
}