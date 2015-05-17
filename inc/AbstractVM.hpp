/*             .-'''''-.
             .'         `.
            :             :   File       : AbstractVM.hpp
           :               :  Creation   : 2015-05-17 03:39:01
           :      _/|      :  Last Edit  : 2015-05-17 07:50:43
            :   =/_/      :   Author     : nsierra-   
             `._/ |     .'    Mail       : nsierra-@student.42.fr  
          (   /  ,|...-'
           \_/^\/||__
        _/~  `""~`"` \_
     __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP
# include <string>
# include "SyntaxChecker.hpp"

class   AbstractVM
{
    public:
        AbstractVM();
        ~AbstractVM(void);
        AbstractVM(AbstractVM const & src);
        AbstractVM &operator=(AbstractVM const & rhs);

        void            setInputFile(const std::string &filename);
        void            checkFileIntegrity(void);

    private:
        SyntaxChecker   _syntaxChecker;
};

#endif /* ABSTRACTVM_HPP */