/*             .-'''''-.
             .'         `.
            :             :   File       : AbstractVM.cpp
           :               :  Creation   : 2015-05-17 03:41:30
           :      _/|      :  Last Edit  : 2015-05-17 07:50:54
            :   =/_/      :   Author     : nsierra-   
             `._/ |     .'    Mail       : nsierra-@student.42.fr  
          (   /  ,|...-'
           \_/^\/||__
        _/~  `""~`"` \_
     __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#include "AbstractVM.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(AbstractVM const & src)
{
    *this = src;
}

AbstractVM::~AbstractVM(void)
{

}

AbstractVM  &AbstractVM::operator=(AbstractVM const & rhs)
{
    if (this != &rhs)
    {
        _syntaxChecker = rhs._syntaxChecker;
    }
    return *this;
}

void        AbstractVM::setInputFile(const std::string &filename)
{
    _syntaxChecker.setFilename(filename);
}

void        AbstractVM::checkFileIntegrity(void)
{
    try {
        _syntaxChecker.analyzeFile();
    } catch (const SyntaxChecker::InvalidInstructionException &e) {
        std::cout 
            << "\"" << e.line << "\""
            << " (line " << e.lineNumber << ") "
            << e.what() << std::endl
        ;
        exit(EXIT_FAILURE);
    } catch (const SyntaxChecker::InvalidValueException &e) {
        std::cout 
            << "\"" << e.line << "\""
            << " (line " << e.lineNumber << ") "
            << e.what() << std::endl
        ;
        exit(EXIT_FAILURE);
    } catch (const SyntaxChecker::FileOpeningFailException &e) {
        std::cout << "\"" << e.file << "\" " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "LIL" << std::endl;
    auto tmp = _syntaxChecker.getTokens();
    for (auto tok : tmp)
        std::cout << tok << std::endl;
}