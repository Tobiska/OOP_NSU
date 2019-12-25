#pragma once
#include "Worker.h"
class Dump : public Common::Worker
{
public:
	Dump() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
