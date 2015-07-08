//               .-'''''-.
//             .'         `.
//            :             :        File       : IOperand.hpp
//           :               :       Creation   : 2015-05-23 06:29:13
//           :      _/|      :       Last Edit  : 2015-07-08 03:10:38
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include "OperandType.hpp"
# include <string>

class		IOperand
{
	public:
		virtual int 			getPrecision(void) const = 0; // Precision of the type of the instance
		virtual eOperandType	getType(void) const = 0; // Type of the instance

		virtual IOperand const * 	operator+(IOperand const & rhs) const = 0; // Sum
		virtual IOperand const * 	operator-(IOperand const & rhs) const = 0; // Difference
		virtual IOperand const * 	operator*(IOperand const & rhs) const = 0; // Product
		virtual IOperand const * 	operator/(IOperand const & rhs) const = 0; // Quotient
		virtual IOperand const * 	operator%(IOperand const & rhs) const = 0; // Modulo

		virtual std::string const & toString(void ) const = 0; // String representation of the instance

		virtual ~IOperand( void ) { };
};

#endif /* IOPERAND_HPP */