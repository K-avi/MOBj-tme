#ifndef ERROR_H 
#define ERROR_H

#include <exception>
#include <string>

namespace Netlist{
    class Error : public std::exception{
        private : 
            std::string message_; 
        public : 
            Error(std::string message) throw(){message_ = message;};
            ~Error() throw() {} ;

            const char* what() const throw() {return message_.c_str();}

    };
}

#endif 