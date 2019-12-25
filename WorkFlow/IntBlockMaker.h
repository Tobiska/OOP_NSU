#pragma once
#include "Worker.h"

class IntBlockMaker
{
public:
	virtual Common::Worker* create() const = 0;

	virtual ~IntBlockMaker() = default;

};
