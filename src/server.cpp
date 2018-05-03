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

    }
    
    
    Server(){

    }

    void add_new_miner(std::thread t){
        this->miners.push_back(t);
    }

    std::vector<std::thread> get_miners(){
        return this->miners;
    }
private:
    std::vector<std::thread> miners;
    Communication *c;
};



int main(int argc, char *argv[]){

    Server *s = new Server();
    std::vector<std::thread> miners;
    miners = s->get_miners();

    int i = 0;
    std::cout << "Choose Miner: " << std::endl;
    for (auto t : miners){

        std::cout << i << " - " << t << " - ";
        std::cout << t.get_miner_ip() << std::endl;
    }
    int choice = std::cin.get();
    std::thread t = miners[choice];

}