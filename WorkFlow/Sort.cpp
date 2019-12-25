#include "Sort.h"
#include "BlockMaker.h"
#include <algorithm>

static BlockMaker<Sort> sortMaker("sort");

std::string Sort::work(const std::string& text, const std::vector<std::string>& data)
{
	if (count != 1) {
		throw std::exception("EXEPRION: invalid readblock and writeblock count");
	}
	if (text.empty() || !data.empty())
	{
		throw std::exception("EXCEPTION: invalid arguments for sort");
	}
	std::string resultStr, tmp = "";
	std::vector<std::string> vec;
	for (size_t it = 0; it != text.size(); ++it)
	{
		if (text[it] == '\n')
		{
			vec.push_back(tmp);
			tmp.clear();
		}
		else tmp += text[it];
	}
	sort(vec.begin(), vec.end());

	for (auto it = 0; it != vec.size(); ++it)
	{
		resultStr += vec[it] + "\n";
	}

	return resultStr;
}