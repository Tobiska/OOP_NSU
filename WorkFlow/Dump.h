#pragma once
#include "Worker.h"
#include "Inter.h"
class Dump : public Common::Worker,public G::Inter
{
public:
	Dump() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
