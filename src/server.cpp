#include <iostream>
#include <pthread.h>
#include <thread>
#include "communication.h"
#include "save_info.h"

class Server{
public:
    Server(){

    }

private:
    char * server_addrs;

};

int main(int argc, char *argv[]){
    Server *s = new Server();
    
    
}