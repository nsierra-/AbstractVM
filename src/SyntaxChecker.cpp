//               .-'''''-.
//             .'         `.
//            :             :        File       : SyntaxChecker.cpp
//           :               :       Creation   : 2015-07-08 02:51:23
//           :      _/|      :       Last Edit  : 2015-07-08 08:19:20
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /        /-'`  `\   \  \-

#include "SyntaxChecker.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include <fstream>

const char          SyntaxChecker::_commentChar = ';';
const std::regex    SyntaxChecker::_instructionPattern("\\s*(push)\\s+(\\S+)\\s*(?:;?.*)|\\s*(pop)\\s*(?:;?.*)|\\s*(dump)\\s*(?:;?.*)|\\s*(assert)\\s+(\\S+)\\s*(?:;?.*)|\\s*(add)\\s*(?:;?.*)|\\s*(sub)\\s*(?:;?.*)|\\s*(mul)\\s*(?:;?.*)|\\s*(div)\\s*(?:;?.*)|\\s*(mod)\\s*(?:;?.*)|\\s*(print)\\s*(?:;?.*)|\\s*(exit)\\s*(?:;?.*)|\\s*(;;)\\s*(?:;?.*)|\\s*");
const std::regex    SyntaxChecker::_valuePattern("(int8)\\(([-+]?\\d+)\\)|(int16)\\(([-+]?\\d+)\\)|(int32)\\(([-+]?\\d+)\\)|(float)\\(([-+]?[0-9]+\\.[0-9]+)\\)|(double)\\(([-+]?[0-9]+\\.[0-9]+)\\)");

static inline std::string &ltrim(std::string &s)
{
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
}

static inline std::string &rtrim(std::string &s)
{
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
}

static inline std::string &trim(std::string &s) { return ltrim(rtrim(s)); }

SyntaxChecker::SyntaxChecker(const std::string filename, bool valid) :
	_filename(filename),
	_valid(valid),
	_endTokenFound(false),
	_tokens()
{
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(1, &SyntaxChecker::_valueValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(3, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(4, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(5, &SyntaxChecker::_valueValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(7, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(8, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(9, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(10, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(11, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(12, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(13, &SyntaxChecker::_simpleValidation));
	_instructionsIndex.push_back(std::make_pair<unsigned int, SCVerifyFun>(14, &SyntaxChecker::_simpleValidation));
}

SyntaxChecker::SyntaxChecker(SyntaxChecker const & src) :
	_filename(src._filename)
{
	*this = src;
}

SyntaxChecker::~SyntaxChecker(void)
{

}

SyntaxChecker   &SyntaxChecker::operator=(SyntaxChecker const & rhs)
{
	if (this != &rhs)
	{
		_valid = rhs._valid;
		_tokens = rhs._tokens;
	}
	return *this;
}

bool        SyntaxChecker::_instructionIsValid(const std::string &line, unsigned int lineNumber)
{
	std::smatch     sm;
	std::string     tmp;
	std::string     to_process;

	std::regex_match(line, sm, _instructionPattern);

	if (sm.size() == 0)
		return tmp = line, trim(tmp)[0] == ';';

	if (static_cast<std::string>(sm[14]) == ";;")
		_endTokenFound = true;

	for (auto &i : _instructionsIndex)
	{
		tmp = sm[i.first];
		if (tmp.size() != 0)
		{
			if (!(*this.*i.second)(sm, i.first))
			{
				_invalidValueEx.lineNumber = lineNumber;
				_invalidValueEx.line = line;
				throw _invalidValueEx;
			}
		}
	}
	return true;
}

void        SyntaxChecker::analyzeFile(void)
{
	std::ifstream   infile(_filename);
	std::string     line;
	size_t          lineNumber;

	lineNumber = 1;

	if (!infile.good())
	{
		_fileOpeningFailEx.file = _filename;
		throw _fileOpeningFailEx;
	}
	_tokens.clear();

	while (std::getline(infile, line))
	{

		if (!_instructionIsValid(line, lineNumber))
		{
			_invalidInstructionEx.lineNumber = lineNumber;
			_invalidInstructionEx.line = line;
			throw _invalidInstructionEx;
		}

		if (_endTokenFound)
		{
			_needlessEndTokenEx.lineNumber = lineNumber;
			_needlessEndTokenEx.line = line;
			throw _needlessEndTokenEx;
		}
		++lineNumber;
	}

	if (lineNumber == 1)
	{
		_fileOpeningFailEx.file = _filename;
		throw _fileOpeningFailEx;
	}
	_valid = true;
}

void        SyntaxChecker::analyzeStdin(void)
{
	std::ifstream   infile(_filename);
	std::string     line;
	unsigned		lineNumber = 1;

	_tokens.clear();

	while (std::getline(std::cin, line))
	{

		if (!_instructionIsValid(line, lineNumber))
		{
			_invalidInstructionEx.lineNumber = lineNumber;
			_invalidInstructionEx.line = line;
			throw _invalidInstructionEx;
		}

		if (_endTokenFound)
			break ;

		++lineNumber;
	}

	if (lineNumber == 1)
		throw _emptyProgramEx;

	if (!_endTokenFound)
	{
		_noEndTokenEx.lineNumber = lineNumber;
		_noEndTokenEx.line = line;
		throw _noEndTokenEx;
	}
	_valid = true;
}

bool                        SyntaxChecker::_simpleValidation(const std::smatch &matches, unsigned int i)
{
	_tokens.push_back(matches[i]);
	return true;
}

bool                        SyntaxChecker::_valueValidation(const std::smatch &matches, unsigned int i)
{
	std::smatch             sm;
	std::string             tmp = matches[i + 1];
	int                     j = 0;

	std::regex_match(tmp, sm, _valuePattern);


	if (sm.size() == 0)
		return false;

	_tokens.push_back(matches[i]);
	for (auto & tok : sm)
	{
		if (j == 0 && (j = 1))
			continue ;
		if (!static_cast<std::string>(tok).empty())
			_tokens.push_back(static_cast<std::string>(tok));
	}
	return true;
}

void                        SyntaxChecker::setFile(const std::string & filename) { _filename = filename; }

std::vector<std::string> &	SyntaxChecker::getTokens(void) { return _tokens; }
bool                        SyntaxChecker::isValid(void) const  { return _valid; }
