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

AbstractVM &	AbstractVM::operator=(AbstractVM const & rhs)
{
	if (this != &rhs)
	{
		_syntaxChecker = rhs._syntaxChecker;
	}
	return *this;
}

int			AbstractVM::doTheJob(int ac, const char ** av)
{
	if (ac > 2)
		return std::cout << "Usage : ./avm [file]" << std::endl, EXIT_FAILURE;
	else if (ac == 2)
	{
		setInputFile(av[1]);
		getProgram(&SyntaxChecker::analyzeFile);
	}
	else if (ac == 1)
		getProgram(&SyntaxChecker::analyzeStdin);
	return _executeProgram();
}

void        AbstractVM::setInputFile(const std::string & filename)
{
	_syntaxChecker.setFile(filename);
}

void		AbstractVM::getProgram(void (SyntaxChecker::* p)())
{
	try {
		(_syntaxChecker.*p)();
	} catch (const SyntaxChecker::SyntaxCheckerException & e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

int			AbstractVM::_executeProgram(void)
{
	std::cout << "ici" << std::endl;
	return EXIT_SUCCESS;
}
