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
	catch (MyException &ex) {
		std::cerr << ex.what() << ex.number_or_id() << std::endl;
		std::cerr << ex.WFile();
	}
	return 0;
}