#pragma once
#include "Workflow.h"
namespace Common
{
	class Worker
	{
	public:
		virtual std::string work(const std::string &text, const std::vector<std::string> &data) = 0;

		~Worker() = default;
	
		static int count;

	};
}
//int Common::Worker::count = 0;
