#pragma once
#include "Worker.h"
#include "Inter.h"
class Write : public Common::Worker,public G::Inter
{
public:
	Write() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
