#pragma once
#include <map>
#include "Worker.h"
#include "Dump.h"
#include "Read.h"
#include "Write.h"
#include "Grep.h"
#include "Sort.h"
#include "Replace.h"
#include "IBlockMaker.h"


namespace Common {

	class Factory
	{
		Factory() = default;
	public:
		Factory(const Factory&) = delete;
		Factory& operator = (const Factory&) = delete;
		static Factory& Object();

		~Factory() = default;

		Worker* createBlock(std::string blockName);

		void registerBlock(std::string newBlockName, IBlockMaker* newBlock);
	private:
		std::map<std::string, IBlockMaker*> _blockMap;
	};
}