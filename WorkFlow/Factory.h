#pragma once
#include <map>
#include "Worker.h"
#include "Dump.h"
#include "Read.h"
#include "Write.h"
#include "Grep.h"
#include "Sort.h"
#include "Replace.h"
#include "IntBlockMaker.h"
#include<iostream>

namespace Common {

	class Factory
	{
		Factory() = default;
	public:
		static Factory& Object();

		~Factory() = default;

		Worker* createBlock(std::string blockName);

		void registerBlock(std::string newBlockName, IntBlockMaker* newBlock);
	private:
		std::map<std::string,IntBlockMaker*> _blockMap;
	};
}