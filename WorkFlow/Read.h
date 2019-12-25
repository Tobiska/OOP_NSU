#pragma once
#include "Worker.h"
#include "Inter.h"
class Read : public Common::Worker,public G::Inter
{
public:
	Read() = default;
	std::string work(const std::string& text, const std::vector<std::string>& data) override;
};
