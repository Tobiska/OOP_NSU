#include "Factory.h"
#include <iostream>

using namespace Common;

Factory& Factory::Object()
{
	static Factory factory;
	return factory;
}


Worker* Common::Factory::createBlock(std::string blockName)
{
	auto block = _blockMap.find(blockName);
	IntBlockMaker* blockMaker = block->second;
	return blockMaker->create();
}



void Common::Factory::registerBlock(std::string newBlockName, IntBlockMaker* newBlock)
{
	if (_blockMap.find(newBlockName) != _blockMap.end())
	{
		throw new std::exception("error, multiple makers for this block name");
	}
	_blockMap[newBlockName] = newBlock;
}