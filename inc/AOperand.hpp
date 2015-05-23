//               .-'''''-.
//             .'         `.
//            :             :        File       : AOperand.hpp
//           :               :       Creation   : 2015-05-23 06:42:17
//           :      _/|      :       Last Edit  : 2015-05-23 06:44:44
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef AOPERAND_HPP
# define AOPERAND_HPP

# include "OperandeType.hpp"

class	AOperand : public IOperand
{
	public:
		AOperand(void);
		virtual ~AOperand(void);
		AOperand(AOperand const & src);
		AOperand &operator=(AOperand const & rhs);

		virtual int 				getPrecision(void) const;
		virtual eOperandType 		getType(void) const;

		virtual IOperand const * 	operator+(IOperand const & rhs) const;
		virtual IOperand const * 	operator-(IOperand const & rhs) const;
		virtual IOperand const * 	operator*(IOperand const & rhs) const;
		virtual IOperand const * 	operator/(IOperand const & rhs) const;
		virtual IOperand const * 	operator%(IOperand const & rhs) const;

		virtual std::string const & toString(void ) const;

	private:
		OperandeType	_type;
};

#endif /* AOPERAND_HPP */