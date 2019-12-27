#include "Write.h"
#include "BlockMaker.h"
#include "MyException.h"
static BlockMaker<Write> writefileMaker("writefile");

std::string Write::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count < 0) {
		throw MyException("EXCEPTION: invalid Write and Read count","Write.cpp");
	}

	count--;
	std::ofstream out;
	out.open(data[0]);

	if (!out.is_open())
	{
		throw MyException("EXCEPTION: can't open file", "Write.cpp");
	}
	out << text;

	out.close();
	return "Writing have finished";
}