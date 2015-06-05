//               .-'''''-.
//             .'         `.
//            :             :        File       : OperandType.hpp
//           :               :       Creation   : 2015-05-23 06:33:43
//           :      _/|      :       Last Edit  : 2015-05-23 06:35:09
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef OPERANDTYPE_HPP
# define OPERANDTYPE_HPP

typedef enum : int
{
	UNDEF,
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
}			eOperandType;

#endif /* OPERANDTYPE_HPP */
