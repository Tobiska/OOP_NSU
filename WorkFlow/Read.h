#pragma once
#include "Worker.h"
class Read : public Common::Worker
{
public:
	Read() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
