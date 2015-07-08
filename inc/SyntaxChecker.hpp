/*             .-'''''-.
			 .'         `.
			:             :   File       : SyntaxChecker.hpp
		   :               :  Creation   : 2015-05-17 05:05:27
		   :      _/|      :  Last Edit  : 2015-05-17 07:50:49
			:   =/_/      :   Author     : nsierra-
			 `._/ |     .'    Mail       : nsierra-@student.42.fr
		  (   /  ,|...-'
		   \_/^\/||__
		_/~  `""~`"` \_
	 __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#ifndef SYNTAXCHECKER_HPP
# define SYNTAXCHECKER_HPP
# include <string>
# include <regex>
# include <vector>
# include <sstream>
# include "SyntaxCheckerExceptions.hpp"

class   SyntaxChecker
{
	public:
		typedef bool (SyntaxChecker::* SCVerifyFun)(const std::smatch &, unsigned int);
		using InstructionVector = std::vector<std::pair<unsigned int, SCVerifyFun> >;

		SyntaxChecker(const std::string = "", bool = false);
		~SyntaxChecker(void);
		SyntaxChecker(SyntaxChecker const & src);
		SyntaxChecker &	operator=(SyntaxChecker const & rhs);

		bool						isValid(void) const;
		std::vector<std::string> &	getTokens(void);
		void						setFile(const std::string & filename);
		void						analyzeFile(void);
		void						analyzeStdin(void);

	private:
		std::string					_filename;
		static const char			_commentChar;
		static const std::regex		_instructionPattern;
		static const std::regex		_valuePattern;

		bool						_valid;
		bool						_endTokenFound;
		std::vector<std::string>	_tokens;
		InstructionVector			_instructionsIndex;

		InvalidInstructionException	_invalidInstructionEx;
		EmptyProgramException		_emptyProgramEx;
		NoEndTokenException			_noEndTokenEx;
		NeedlessEndTokenException	_needlessEndTokenEx;
		InvalidValueException		_invalidValueEx;
		FileOpeningFailException	_fileOpeningFailEx;

		bool						_instructionIsValid(const std::string &line, unsigned int lineNumber);

		bool						_simpleValidation(const std::smatch &matches, unsigned int i);
		bool						_valueValidation(const std::smatch &matches, unsigned int i);
};

#endif /* SYNTAXCHECKER_HPP */
