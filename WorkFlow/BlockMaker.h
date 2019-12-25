#pragma once
#include "IntBlockMaker.h"
#include "Factory.h"

template <typename T>

class BlockMaker : public IntBlockMaker {
public:
	BlockMaker(std::string key) {
		Common::Factory::Object().registerBlock(key, this);
	}

	virtual Common::Worker* create() const {
		return new T();
	}

};
