#include "Grep.h"
#include "BlockMaker.h"

static BlockMaker<Grep> grepMaker("grep");

std::string Grep::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count != 1) {
		throw std::exception("EXEPRION: invalid readblock and writeblock count");
	}

	if (data.empty() || data.size() > 1 || text.empty())
	{
		throw  std::exception("EXCEPTION: invalid arguments for dump");
	}
	std::string word = data[0];
	std::string tmp = "", resultStr = "";
	for (size_t it = 0; it != text.size(); ++it)
	{
		if (text[it] == '\n')
		{
			if (tmp.find(word) != -1)
			{
				tmp += "\n";
				resultStr += tmp;
			}
			tmp.clear();
		}
		else tmp += text[it];
	}

	return resultStr;
}