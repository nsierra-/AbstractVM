//               .-'''''-.
//             .'         `.
//            :             :        File       : AOperand.cpp
//           :               :       Creation   : 2015-05-23 06:44:55
//           :      _/|      :       Last Edit  : 2015-05-23 06:46:46
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#include "AOperand.hpp"


AOperand::AOperand()
{

}

AOperand::AOperand(AOperand const & src)
{
	*this = src;
}

AOperand::~AOperand(void)
{

}

AOperand	&AOperand::operator=(AOperand const & rhs)
{
	if (this != &rhs)
	{

	}
	return *this;
}

int 				AOperand::getPrecision(void) const
{

}
eOperandType 		AOperand::getType(void) const
{
	return _type;
}

IOperand const * 	AOperand::operator+(IOperand const & rhs) const
{

}

IOperand const * 	AOperand::operator-(IOperand const & rhs) const
{

}

IOperand const * 	AOperand::operator*(IOperand const & rhs) const
{

}

IOperand const * 	AOperand::operator/(IOperand const & rhs) const
{

}

IOperand const * 	AOperand::operator%(IOperand const & rhs) const
{

}

std::string const & AOperand::toString(void ) const
{

}