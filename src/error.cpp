#include "error.h"


void Error::exit_error(std::string s){
    std::cout << s << std::endl;
    exit(-1);
}


void Error::log_error(std::string s){
    std::cout << s << std::endl;
}
