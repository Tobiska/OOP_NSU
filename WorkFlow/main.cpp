#include <iostream>
#include "Workflow.h"
#include "Replace.h"

using namespace Common;

int main()
{
	WorkFlow wf;
	try {
		wf.start("workflow.txt");
	}
	catch (std::exception &ex) {
		std::cerr << ex.what();
	}
	return 0;
}