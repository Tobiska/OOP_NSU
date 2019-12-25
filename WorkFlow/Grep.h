#pragma once
#include "Worker.h"
class Grep : public Common::Worker
{
public:
	Grep() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};

