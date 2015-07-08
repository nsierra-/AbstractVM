//               .-'''''-.
//             .'         `.
//            :             :        File       : SyntaxCheckerExceptions.hpp
//           :               :       Creation   : 2015-07-08 08:29:45
//           :      _/|      :       Last Edit  : 2015-07-08 08:32:22
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /        /-'`  `\   \  \-

#ifndef SYNTAXCHECKEREXCEPTIONS_HPP
# define SYNTAXCHECKEREXCEPTIONS_HPP

class  SyntaxCheckerException : public std::exception
{
	public:
		SyntaxCheckerException();
		SyntaxCheckerException(SyntaxCheckerException const &src);
		virtual ~SyntaxCheckerException(void) throw();

		SyntaxCheckerException &operator=(SyntaxCheckerException const &rhs);

		virtual const char *what() const throw();

		size_t                  lineNumber;
		std::string             line;
};

class   EmptyProgramException : public SyntaxCheckerException
{
	public:
		EmptyProgramException();
		EmptyProgramException(EmptyProgramException const &src);
		virtual ~EmptyProgramException(void) throw();

		virtual const char * what() const throw();
};

class   NoEndTokenException : public SyntaxCheckerException
{
	public:
		NoEndTokenException();
		NoEndTokenException(NoEndTokenException const &src);
		virtual ~NoEndTokenException(void) throw();

		virtual const char * what() const throw();
};

class   NeedlessEndTokenException : public SyntaxCheckerException
{
	public:
		NeedlessEndTokenException();
		NeedlessEndTokenException(NeedlessEndTokenException const &src);
		virtual ~NeedlessEndTokenException(void) throw();

		virtual const char * what() const throw();
};

class   InvalidInstructionException : public SyntaxCheckerException
{
	public:
		InvalidInstructionException();
		InvalidInstructionException(InvalidInstructionException const &src);
		virtual ~InvalidInstructionException(void) throw();

		virtual const char * what() const throw();
};

class   InvalidValueException : public SyntaxCheckerException
{
	public:
		InvalidValueException();
		InvalidValueException(InvalidValueException const &src);
		virtual ~InvalidValueException(void) throw();

		virtual const char * what() const throw();
};

class   FileOpeningFailException : public SyntaxCheckerException
{
	public:
		FileOpeningFailException();
		FileOpeningFailException(FileOpeningFailException const &src);
		virtual ~FileOpeningFailException(void) throw();

		FileOpeningFailException &operator=(FileOpeningFailException const &rhs);

		virtual const char * what() const throw();

		std::string             file;
};

#endif
