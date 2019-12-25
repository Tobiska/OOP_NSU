#pragma once
#include "Worker.h"
class Replace : public Common::Worker
{
public:
	Replace() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
