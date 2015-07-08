//               .-'''''-.
//             .'         `.
//            :             :        File       : SyntaxCheckerExceptions.cpp
//           :               :       Creation   : 2015-07-08 03:37:51
//           :      _/|      :       Last Edit  : 2015-07-08 08:33:47
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /        /-'`  `\   \  \-

#include "SyntaxChecker.hpp"

SyntaxCheckerException::SyntaxCheckerException()
{

}

SyntaxCheckerException::SyntaxCheckerException(SyntaxCheckerException const & src)
{
	*this = src;
}

SyntaxCheckerException::~SyntaxCheckerException(void) throw()
{

}

SyntaxCheckerException  &SyntaxCheckerException::operator=(SyntaxCheckerException const & rhs)
{
	lineNumber = rhs.lineNumber;
	line = rhs.line;
	return *this;
}
const char *	SyntaxCheckerException::what() const throw()
{
 return "Syntax Checker Exception (You should not see this)";
}


NoEndTokenException::NoEndTokenException()
{

}

NoEndTokenException::NoEndTokenException(NoEndTokenException const & src)
{
 *this = src;
}

NoEndTokenException::~NoEndTokenException(void) throw()
{

}

const char *	NoEndTokenException::what() const throw()
{
 return "End of program token (;;) not found.";
}


NeedlessEndTokenException::NeedlessEndTokenException()
{

}

NeedlessEndTokenException::NeedlessEndTokenException(NeedlessEndTokenException const & src)
{
 *this = src;
}

NeedlessEndTokenException::~NeedlessEndTokenException(void) throw()
{

}

const char *	NeedlessEndTokenException::what() const throw()
{
 return "Superfluous end of program token (;;) found. Use it only when using avm with stdin.";
}


InvalidInstructionException::InvalidInstructionException()
{

}

InvalidInstructionException::InvalidInstructionException(InvalidInstructionException const & src)
{
 *this = src;
}

InvalidInstructionException::~InvalidInstructionException(void) throw()
{

}

const char *	InvalidInstructionException::what() const throw()
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

InvalidValueException::InvalidValueException()
{

}

InvalidValueException::InvalidValueException(InvalidValueException const & src)
{
 *this = src;
}

InvalidValueException::~InvalidValueException(void) throw()
{

}

const char *	InvalidValueException::what() const throw()
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

FileOpeningFailException::FileOpeningFailException()
{

}

FileOpeningFailException::FileOpeningFailException(FileOpeningFailException const & src)
{
 *this = src;
}

FileOpeningFailException::~FileOpeningFailException(void) throw()
{

}

FileOpeningFailException &FileOpeningFailException::operator=(FileOpeningFailException const & rhs)
{
	file = rhs.file;
	return *this;
}
const char *	FileOpeningFailException::what() const throw()
{
	static std::stringstream    ss;

	ss.str("");
	ss
		<< "\"" << file << "\" " << std::endl
		<< "Error while opening file. Please check you entered a valid path."
	;
	return ss.str().c_str();
}

EmptyProgramException::EmptyProgramException()
{

}

EmptyProgramException::EmptyProgramException(EmptyProgramException const & src)
{
	*this = src;
}

EmptyProgramException::~EmptyProgramException(void) throw()
{

}

const char *	EmptyProgramException::what() const throw()
{
	return "Program seems empty.";
}
