#ifndef MINER_H
#define MINER_H
#include <iostream>
#include <string>

class Miner{
private:
    std::string id;
    char * ip;
public:
    std::string get_miner_id();
    char * get_miner_ip();
};

#endif