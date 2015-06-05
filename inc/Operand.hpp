//               .-'''''-.
//             .'         `.
//            :             :        File       : Operand.hpp
//           :               :       Creation   : 2015-05-23 06:42:17
//           :      _/|      :       Last Edit  : 2015-05-23 06:44:44
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef Operand_HPP
# define Operand_HPP

# include "IOperand.hpp"
# include "OperandType.hpp"

template<typename T>
class	Operand : public IOperand
{
	public:
		Operand(eOperandType = UNDEF, T = 0);
		virtual ~Operand(void);
		Operand(Operand const & src);
		Operand &operator=(Operand const & rhs);

		virtual int 				getPrecision(void) const;
		virtual eOperandType 		getType(void) const;

		virtual IOperand const		*operator+(IOperand const & rhs) const;
		virtual IOperand const		*operator-(IOperand const & rhs) const;
		virtual IOperand const		*operator*(IOperand const & rhs) const;
		virtual IOperand const		*operator/(IOperand const & rhs) const;
		virtual IOperand const		*operator%(IOperand const & rhs) const;

		virtual std::string const & toString(void ) const;

	private:
		const eOperandType	_type;
		T					_val;
};

#endif /* Operand_HPP */
