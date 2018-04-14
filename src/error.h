#ifndef ERROR_H
#define ERROR_H

#include<iostream>

class Error{

    static void exit_error(std::string);
    static void log_error(std::string);
};


#endif