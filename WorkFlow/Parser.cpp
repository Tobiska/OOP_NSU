#include "Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "MyException.h"
using namespace Common;

void Parser::parse(std::string fileName)
{
	try
	{
		_fin.open(fileName);
	}
	catch (MyException &e)
	{
		throw MyException("EXCEPTION: can't open file ", "Parser.cpp");
	}
	std::string tmp;
	try
	{
		getline(_fin, tmp);
	}
	catch (MyException &e)
	{
		throw MyException("EXCEPTION: unexpected end of file ", "Parser.cpp");
	}
	std::vector <std::string> splited = _split(tmp, ' ');
	if (splited.size() > 1)
	{
		throw MyException("EXCEPTION: invalid input format line #", "Parser.cpp",1);
		//std::cerr << "EXCEPTION: invalid input format line #" << 1 << std::endl;
		//_fin.close();
		//exit(1);
	}
	if (splited[0] != "desc")
	{
		throw MyException("EXCEPTION: string ""desc"" is not found", "Parser.cpp", 1);
		//std::cerr << "EXCEPTION: string ""desc"" is not found" << std::endl;
		//_fin.close();
		//exit(1);
	}

	size_t number_of_line = 2;

	while (true)
	{
		try
		{
			getline(_fin, tmp);
		}
		catch (MyException &e)
		{

			throw MyException("EXCEPTION: unexpected end of file ", "Parser.cpp");
		}
		splited = _split(tmp, ' ');



		if (splited.size() == 1)
		{
			if (splited[0] == "csed")
			{
				break;
			}
			else
			{
				throw MyException("EXCEPTION: string ""csed"" is not found", "Parser.cpp");
				//std::cerr << "EXCEPTION: string ""csed"" is not found" << std::endl;
				//_fin.close();
				//exit(1);
			}
		}
		if (splited.size() < 3)
		{
			throw MyException("EXCEPTION: invalid input format ", "Parser.cpp",number_of_line);
			//std::cerr << "EXCEPTION: invalid input format line #" << number_of_line << std::endl;
			//_fin.close();
			//exit(1);
		}
		size_t id = _stringToInt(splited[0], number_of_line);

		if (_parsedData.count(id))
		{
			throw MyException("EXCEPTION: reused ID ", "Parser.cpp", id);
			//std::cerr << "EXCEPTION: reused ID " << id  << std::endl;
			//_fin.close();
			//exit(1);
		}
		if (splited[1] != "=")
		{
			throw MyException("EXCEPTION: = is not found line #", "Parser.cpp", number_of_line);
			//std::cerr << "EXCEPTION: = is not found line #" << number_of_line << std::endl;
			//_fin.close();
			//exit(1);
		}
		_parsedData[id] = std::vector<std::string>(splited.begin() + 2, splited.end());
		_keys.push_back(id);
		splited.clear();
		number_of_line++;
	}
	try
	{
		getline(_fin, tmp);
	}
	catch (MyException &e)
	{
		throw MyException("EXCEPTION: unexpected end of file ", "Parser.cpp");
	}
	splited = _split(tmp, ' ');
	if (splited.size() % 2 == 0)
	{
		throw MyException("EXCEPTION: unexpected end of file ", "Parser.cpp");
		//_fin.close();
		//exit(1);
	}

	for (size_t i = 0; i < splited.size(); i += 2)
	{
		size_t id = _stringToInt(splited[i], number_of_line);
		if (!_parsedData.count(id))
		{
			throw MyException("EXCEPTION: unexpected end of file ", "Parser.cpp",id);
			//_fin.close();
			//exit(1);
		}
		_sequence.push_back(id);
		if (i != splited.size() - 1 && splited[i + 1] != "->")
		{
			throw MyException("EXCEPTION: unexpected end of file ", "Parser.cpp",number_of_line);
		}
	}
	_fin.close();
}

std::unordered_map <size_t, std::vector<std::string>> Common::Parser::getData() const
{
	return _parsedData;
}

std::vector<size_t> Common::Parser::getSequence() const
{
	return _sequence;
}

std::vector<size_t> Common::Parser::getKeys() const
{
	return _keys;
}

std::vector<std::string> Parser::_split(const std::string& s, char delim)
{
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim))
	{
		result.push_back(item);
	}
	return result;
}

void Parser::_wrongIdException(std::string& id, size_t number_of_line)
{
	int id_int = atoi(id.c_str());
	throw MyException("EXCEPTION: invalid ID format ", "Parser.cpp", id_int);
}

size_t Parser::_stringToInt(std::string& s, size_t number_of_line)
{
	if (s.size() > 9 || (s.size() > 1 && s[0] == '0'))
	{
		_wrongIdException(s, number_of_line);
	}
	size_t id = 0, p10 = 1;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			_wrongIdException(s, number_of_line);
		}
		id += p10 * (s[i] - '0');
		p10 *= 10;
	}
	return id;
}