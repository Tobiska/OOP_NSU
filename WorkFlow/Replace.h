#pragma once
#include "Worker.h"
#include "Inter.h"
class Replace : public Common::Worker,public G::Inter
{
public:
	Replace() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
