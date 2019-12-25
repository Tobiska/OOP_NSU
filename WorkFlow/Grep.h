#pragma once
#include "Worker.h"
#include "Inter.h"
class Grep : public Common::Worker,public G::Inter
{
public:
	Grep() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};

