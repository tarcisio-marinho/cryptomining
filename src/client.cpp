#include "communication.h"
#include<iostream>
int main(int argc, char * argv[]){

    std::cout << "hello world!" << std::endl;
    Communication c("127.0.0.1", 8888);

    while(true){
        c.connect_forever();

        std::string output = c.recv_message();
        if(output.length() == 0){
            Error::log_error("connection finished");
        }
        c.send_message("sup brother");
    }
}