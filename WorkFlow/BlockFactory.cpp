#include "Factory.h"
#include <iostream>

using namespace Common;

Factory& Factory::Object()
{
	static Factory factory;
	return factory;
}

Worker* Factory::createBlock(std::string blockName)
{
	auto block = _blockMap.find(blockName);
	IBlockMaker* blockMaker = block->second;
	return blockMaker->create();
}

void Factory::registerBlock(std::string newBlockName, IBlockMaker* newBlock)
{
	if (_blockMap.find(newBlockName) != _blockMap.end())
	{
		throw new std::exception("error, multiple makers for this block name");
	}
	_blockMap[newBlockName] = newBlock;
}