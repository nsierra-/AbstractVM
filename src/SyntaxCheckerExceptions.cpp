//               .-'''''-.
//             .'         `.
//            :             :        File       : SyntaxCheckerExceptions.cpp
//           :               :       Creation   : 2015-07-08 03:37:51
//           :      _/|      :       Last Edit  : 2015-07-08 03:44:12
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /        /-'`  `\   \  \-

#include "SyntaxChecker.hpp"

SyntaxChecker::SyntaxCheckerException::SyntaxCheckerException()
{

}

SyntaxChecker::SyntaxCheckerException::SyntaxCheckerException(SyntaxChecker::SyntaxCheckerException const & src)
{
	*this = src;
}

SyntaxChecker::SyntaxCheckerException::~SyntaxCheckerException(void) throw()
{

}

SyntaxChecker::SyntaxCheckerException  &SyntaxChecker::SyntaxCheckerException::operator=(SyntaxChecker::SyntaxCheckerException const & rhs)
{
	lineNumber = rhs.lineNumber;
	line = rhs.line;
	return *this;
}
const char *	SyntaxChecker::SyntaxCheckerException::what() const throw()
{
 return "Syntax Checker Exception (You should not see this)";
}


SyntaxChecker::NoEndTokenException::NoEndTokenException()
{

}

SyntaxChecker::NoEndTokenException::NoEndTokenException(SyntaxChecker::NoEndTokenException const & src)
{
 *this = src;
}

SyntaxChecker::NoEndTokenException::~NoEndTokenException(void) throw()
{

}

const char *	SyntaxChecker::NoEndTokenException::what() const throw()
{
 return "End of program token (;;) not found.";
}


SyntaxChecker::NeedlessEndTokenException::NeedlessEndTokenException()
{

}

SyntaxChecker::NeedlessEndTokenException::NeedlessEndTokenException(SyntaxChecker::NeedlessEndTokenException const & src)
{
 *this = src;
}

SyntaxChecker::NeedlessEndTokenException::~NeedlessEndTokenException(void) throw()
{

}

const char *	SyntaxChecker::NeedlessEndTokenException::what() const throw()
{
 return "Superfluous end of program token (;;) found. Use it only when using avm with stdin.";
}


SyntaxChecker::InvalidInstructionException::InvalidInstructionException()
{

}

SyntaxChecker::InvalidInstructionException::InvalidInstructionException(SyntaxChecker::InvalidInstructionException const & src)
{
 *this = src;
}

SyntaxChecker::InvalidInstructionException::~InvalidInstructionException(void) throw()
{

}

const char *	SyntaxChecker::InvalidInstructionException::what() const throw()
{
	static std::stringstream   ss;

	ss.str("");
	ss
		<< "\"" << line << "\"" << std::endl
		<< "(line " << lineNumber << ") "
		<< "Invalid Instruction."
	;
	return ss.str().c_str();
}

SyntaxChecker::InvalidValueException::InvalidValueException()
{

}

SyntaxChecker::InvalidValueException::InvalidValueException(SyntaxChecker::InvalidValueException const & src)
{
 *this = src;
}

SyntaxChecker::InvalidValueException::~InvalidValueException(void) throw()
{

}

const char *	SyntaxChecker::InvalidValueException::what() const throw()
{
	static std::stringstream   ss;

	ss.str("");
	ss
		<< "\"" << line << "\"" << std::endl
		<< "(line " << lineNumber << ") "
		<< "Invalid Value."
	;
	return ss.str().c_str();
}

SyntaxChecker::FileOpeningFailException::FileOpeningFailException()
{

}

SyntaxChecker::FileOpeningFailException::FileOpeningFailException(SyntaxChecker::FileOpeningFailException const & src)
{
 *this = src;
}

SyntaxChecker::FileOpeningFailException::~FileOpeningFailException(void) throw()
{

}

SyntaxChecker::FileOpeningFailException &SyntaxChecker::FileOpeningFailException::operator=(SyntaxChecker::FileOpeningFailException const & rhs)
{
	file = rhs.file;
	return *this;
}
const char *	SyntaxChecker::FileOpeningFailException::what() const throw()
{
	static std::stringstream    ss;

	ss.str("");
	ss
		<< "\"" << file << "\" " << std::endl
		<< "Error while opening file. Please check you entered a valid path."
	;
	return ss.str().c_str();
}
