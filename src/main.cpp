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

	return avm.doTheJob(ac, av);
}
