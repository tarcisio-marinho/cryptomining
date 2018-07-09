#include "error.h"


void Error::exit_error(const std::string& s){
    std::cerr << s << std::endl;
    exit(-1);
}


void Error::log_error(const std::string& s){
    std::cerr << s << std::endl;
}
