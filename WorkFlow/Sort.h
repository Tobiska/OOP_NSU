
#pragma once
#include "Worker.h"
#include "Inter.h"
class Sort : public Common::Worker,public G::Inter
{
public:
	Sort() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
