#include "Replace.h"
#include "BlockMaker.h"

static BlockMaker<Replace> replaceMaker("replace");

std::string Replace::work(const std::string &text, const std::vector<std::string> &data)
{
	if (count != 1) {
		throw MyException("EXEPRION: invalid readblock and writeblock count","Replace.cpp");
	}
	if (text.empty() || data.empty() || data.size() > 2)
	{
		throw MyException("EXCEPTION: invalid arguments for replace","Replace.cpp");
	}
	std::string word1 = data[0], word2 = data[1];
	std::string tmp = text;
	int pos;
	while (tmp.find(word1) != -1)
	{
		pos = tmp.find(word1);
		tmp.erase(pos, word1.size());
		tmp.insert(pos, word2);
	}
	return tmp;
}