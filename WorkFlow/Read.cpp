#include "Read.h"
#include "BlockMaker.h"
#include "MyException.h"
static BlockMaker<Read> readfileMaker("readfile");

std::string Read::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count > 0) {
		throw MyException("EXEPRION: invalid readblock and writeblock count","Read.cpp");
	}

	count++;
	if (data.empty() || data.size() > 1)
	{
		throw MyException("EXCEPTION: invalid arguments for readfile","Read.cpp");
	}
	std::ifstream input_file;
	std::string resultStr = "", tmp;

	input_file.open(data[0]);
	if (!input_file.is_open())
	{
		throw MyException("EXCEPTION: can't open file" ,"Write");
	}

	while (getline(input_file, tmp))
	{
		resultStr += tmp + "\n";
	}
	input_file.close();
	return resultStr;
}