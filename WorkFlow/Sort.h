
#pragma once
#include "Worker.h"
class Sort : public Common::Worker
{
public:
	Sort() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
