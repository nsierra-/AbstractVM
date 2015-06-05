//               .-'''''-.
//             .'         `.
//            :             :        File       : Operand.cpp
//           :               :       Creation   : 2015-05-23 06:44:55
//           :      _/|      :       Last Edit  : 2015-05-23 06:46:46
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#include "Operand.hpp"

template<typename T>
Operand<T>::Operand(eOperandType type, T val) :
	_type(type),
	_val(val)
{

}

template<typename T>
Operand<T>::Operand(Operand const &src) :
	_type(src._type)
{
	*this = src;
}

template<typename T>
Operand<T>::~Operand(void)
{

}

template<typename T>
Operand<T>	&Operand<T>::operator=(Operand const &rhs)
{
	if (this != &rhs)
		_val = rhs._val;
	return *this;
}

template<typename T>
int 				Operand<T>::getPrecision(void) const
{

}

template<typename T>
eOperandType 		Operand<T>::getType(void) const
{
	return _type;
}

template<typename T>
IOperand const		*Operand<T>::operator+(IOperand const &rhs) const
{

}

template<typename T>
IOperand const		*Operand<T>::operator-(IOperand const &rhs) const
{

}

template<typename T>
IOperand const		*Operand<T>::operator*(IOperand const &rhs) const
{

}

template<typename T>
IOperand const		*Operand<T>::operator/(IOperand const &rhs) const
{

}

template<typename T>
IOperand const		*Operand<T>::operator%(IOperand const &rhs) const
{

}

template<typename T>
std::string const & Operand<T>::toString(void ) const
{

}
