#pragma once
#include<iostream>
#include<cstring>
#include<string>
class MyException: public std::exception
{
public:
	MyException(const char* error,const char* FileName, int number_of_line = -1);
	~MyException() = default;
	const char* WFile();
	std::string number_or_id();
private:
	const char* _ProblemFile;
	int _number_of_line_or_id;
};
