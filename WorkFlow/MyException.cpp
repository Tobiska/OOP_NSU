#define _CRT_SECURE_NO_WARNINGS
#include "MyException.h"

MyException::MyException(const char* error,const char* FileName,int number_of_line):exception(error),_ProblemFile(FileName)
{
	_number_of_line_or_id=number_of_line;
}

const char* MyException::WFile()
{
	return _ProblemFile;
}

std::string MyException::number_or_id()
{
	if (_number_of_line_or_id == -1) { return "\n"; }
	return std::to_string(_number_of_line_or_id);
}
