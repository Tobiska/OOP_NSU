#include "Workflow.h"
#include "Parser.h"
#include "Factory.h"
#include <algorithm>

using namespace Common;

void WorkFlow::start(std::string fileName)
{
	Parser parser;
	std::string result = "";
	std::unordered_map<size_t, std::vector<std::string>> parsedData;
	std::vector<size_t> parsedSequence;
	Factory &factory = Factory::Object();
	std::vector<size_t> keys;

	parser.parse(fileName);
	parsedData = parser.getData();
	parsedSequence = parser.getSequence();
	keys = parser.getKeys();
	/*int flag = 0;
	for (size_t i = 0; i < parsedSequence.size(); i++) {
		if (parsedData[parsedSequence[i]][0] == "readfile") {
			flag++;
		}
		if (parsedData[parsedSequence[i]][0] == "writefile" ) {
			flag--;
		}
	}
	if(flag != 0){
		throw std::exception("EXCEPTION: invalid write and read blocks");
		//exit(1);
	}*/

	for (size_t it = 0; it != parsedSequence.size(); ++it)
	{
		for (size_t j = 0; j != keys.size(); ++j)
		{
			if (parsedSequence[it] == keys[j])
			{
				Worker* command = factory.createBlock(parsedData[keys[j]][0]);
				result = command->work(result, std::vector<std::string>(parsedData[keys[j]].begin() + 1, parsedData[keys[j]].end()));
				delete command;
				break;
			}
		}
	}
}