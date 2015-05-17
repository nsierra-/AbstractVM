/*             .-'''''-.
			 .'         `.
			:             :   File       : main.cpp
		   :               :  Creation   : 2015-05-17 02:44:07
		   :      _/|      :  Last Edit  : 2015-05-17 03:11:11
			:   =/_/      :   Author     : nsierra-   
			 `._/ |     .'    Mail       : nsierra-@student.42.fr  
		  (   /  ,|...-'
		   \_/^\/||__
		_/~  `""~`"` \_
	 __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#include <iostream>
#include "AbstractVM.hpp"

int					main(int ac, const char **av)
{
	AbstractVM		avm;

	if (ac == 1)
	{
		std::cout << "Please give an argument" << std::endl;
		return EXIT_FAILURE;
	}
	avm.setInputFile(av[1]);
	avm.checkFileIntegrity();
	return EXIT_SUCCESS;
}