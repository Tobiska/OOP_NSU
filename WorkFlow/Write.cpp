#include "Write.h"
#include "BlockMaker.h"
#include "Inter.h"
static BlockMaker<Write> writefileMaker("writefile");

std::string Write::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count < 0) {
		throw std::exception("EXEPRION: invalid readblock and writeblock count  (Write)");
	}

	count--;
	std::ofstream out;
	out.open(data[0]);

	if (!out.is_open())
	{
		throw std::exception("EXCEPTION: can't open file");
	}
	out << text;

	out.close();
	return "Writing have finished";
}