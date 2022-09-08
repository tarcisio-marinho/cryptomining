#ifndef ERROR_H
#define ERROR_H

#include<iostream>

class Error{
public:
    static void exit_error(const std::string&);
    static void log_error(const std::string&);
};


#endif