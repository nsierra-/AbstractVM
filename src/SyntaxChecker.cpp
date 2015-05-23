/*             .-'''''-.
             .'         `.
            :             :   File       : SyntaxChecker.cpp
           :               :  Creation   : 2015-05-17 05:06:13
           :      _/|      :  Last Edit  : 2015-05-17 07:50:58
            :   =/_/      :   Author     : nsierra-   
             `._/ |     .'    Mail       : nsierra-@student.42.fr  
          (   /  ,|...-'
           \_/^\/||__
        _/~  `""~`"` \_
     __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/


#include "SyntaxChecker.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include <fstream>

const std::regex    SyntaxChecker::_instructionPattern("(push)\\s+(\\S+)|(pop)|(dump)|(assert)\\s+(\\S+)|(add)|(sub)|(mul)|(div)|(mod)|(print)|(exit)");
const std::regex    SyntaxChecker::_valuePattern("(int8)\\(([-+]?\\d+)\\)|(int16)\\(([-+]?\\d+)\\)|(int32)\\(([-+]?\\d+)\\)|(float)\\(([-+]?[0-9]+\\.[0-9]+)\\)|(double)\\(([-+]?[0-9]+\\.[0-9]+)\\)");

SyntaxChecker::SyntaxChecker(const std::string filename, bool valid) :
    _filename(filename),
    _valid(valid),
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

    std::regex_match(line, sm, _instructionPattern);

    if (sm.size() == 0)
        return false;

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
    if (!infile)
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
        ++lineNumber;
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
    for (auto &tok : sm)
    {
        if (j == 0 && (j = 1))
            continue ;
        if (!static_cast<std::string>(tok).empty())
            _tokens.push_back(static_cast<std::string>(tok));
    }
    return true;
}

bool                        SyntaxChecker::_assertValidation(const std::smatch &matches, unsigned int i)
{
    _tokens.push_back(matches[i]);
    _tokens.push_back(matches[i + 1]);
    return true;
}

void                        SyntaxChecker::setFilename(const std::string &filename) { _filename = filename; }

std::vector<std::string>    &SyntaxChecker::getTokens(void) { return _tokens; }
bool                        SyntaxChecker::isValid(void) const  { return _valid; }

/*
**
*/
SyntaxChecker::InvalidInstructionException::InvalidInstructionException() { }
SyntaxChecker::InvalidInstructionException::InvalidInstructionException(SyntaxChecker::InvalidInstructionException const & src) { *this = src; }
SyntaxChecker::InvalidInstructionException::~InvalidInstructionException(void) throw() { }
SyntaxChecker::InvalidInstructionException  &SyntaxChecker::InvalidInstructionException::operator=(SyntaxChecker::InvalidInstructionException const & rhs)
{
    lineNumber = rhs.lineNumber;
    line = rhs.line;
    return *this;
}
const char  *SyntaxChecker::InvalidInstructionException::what() const throw()
{
    return "Invalid Instruction.";
}

SyntaxChecker::InvalidValueException::InvalidValueException() { }
SyntaxChecker::InvalidValueException::InvalidValueException(SyntaxChecker::InvalidValueException const & src) { *this = src; }
SyntaxChecker::InvalidValueException::~InvalidValueException(void) throw() { }
SyntaxChecker::InvalidValueException    &SyntaxChecker::InvalidValueException::operator=(SyntaxChecker::InvalidValueException const & rhs)
{
    lineNumber = rhs.lineNumber;
    line = rhs.line;
    return *this;
}
const char  *SyntaxChecker::InvalidValueException::what() const throw()
{
    return "Invalid Value.";
}

SyntaxChecker::FileOpeningFailException::FileOpeningFailException() { }
SyntaxChecker::FileOpeningFailException::FileOpeningFailException(SyntaxChecker::FileOpeningFailException const & src) { *this = src; }
SyntaxChecker::FileOpeningFailException::~FileOpeningFailException(void) throw() { }
SyntaxChecker::FileOpeningFailException &SyntaxChecker::FileOpeningFailException::operator=(SyntaxChecker::FileOpeningFailException const & rhs)
{
    file = rhs.file;
    return *this;
}
const char  *SyntaxChecker::FileOpeningFailException::what() const throw()
{
    return "Error while opening file. Please check you entered a valid path.";
}