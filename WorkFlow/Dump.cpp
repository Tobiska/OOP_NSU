#include "Dump.h"
#include "BlockMaker.h"

static BlockMaker<Dump> dumpMâaker("dump");

std::string Dump::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count != 1) {
		throw std::exception("EXEPRION: invalid readblock and writeblock count");
	}
	if (data.empty() || text.empty() || data.size() > 1)
	{
		throw std::runtime_error("EXCEPTION: invalid arguments for dump");
	}
	std::ofstream out;
	out.open(data[0]);
	if (!out.is_open())
	{
		throw std::exception("EXCEPTION: can't open file");
	}
	out << text;

	out.close();
	return text;
}