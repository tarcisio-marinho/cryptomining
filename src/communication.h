#ifndef COMUNICATION_H
#define COMUNICATION_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <pthread.h>
#include <thread>
#include "error.h"

/* Socket interface */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Communication{

public:
    /* Client functions */
    Communication();
    void get_server_info();


private:

};

#endif 
