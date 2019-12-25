#include "Read.h"
#include "BlockMaker.h"

static BlockMaker<Read> readfileMaker("readfile");

std::string Read::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count > 0) {
		throw std::exception("EXEPRION: invalid readblock and writeblock count  (Read)");
	}

	count++;
	if (data.empty() || data.size() > 1)
	{
		throw new std::exception("EXCEPTION: invalid arguments for readfile");
	}
	std::ifstream input_file;
	std::string resultStr = "", tmp;

	input_file.open(data[0]);
	if (!input_file.is_open())
	{
		throw std::exception("EXCEPTION: can't open file ");
	}

	while (getline(input_file, tmp))
	{
		resultStr += tmp + "\n";
	}
	input_file.close();
	return resultStr;
}