#include "communication.h"

int main(int argc, char *argv[]){
    char * s = "Hello world";

    Communication c("127.0.0.1", 8888);
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