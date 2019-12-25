#pragma once
#include "Worker.h"
class Write : public Common::Worker
{
public:
	Write() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
