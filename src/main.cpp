/*             .-'''''-.
			 .'         `.
			:             :   File       : main.cpp
		   :               :  Creation   : 2015-05-17 02:44:07
		   :      _/|      :  Last Edit  : 2015-05-17 07:51:05
			:   =/_/      :   Author     : nsierra-
			 `._/ |     .'    Mail       : nsierra-@student.42.fr
		  (   /  ,|...-'
		   \_/^\/||__
		_/~  `""~`"` \_
	 __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#include <iostream>
#include "AbstractVM.hpp"

int                 main(int ac, const char **av)
{
	AbstractVM      avm;

	if (ac == 2)
	{
		avm.setInputFile(av[1]);
		avm.checkFileIntegrity();
	}
	else if (ac == 1)
		avm.getProgramFromStdin();
	else
		std::cout << "kek" << std::endl;
	return EXIT_SUCCESS;
}