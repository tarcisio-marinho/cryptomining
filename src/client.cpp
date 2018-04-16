#include "communication.h"

//bool lock_task_manager = false;

int main(int argc, char * argv[]){

    Tasks::check_task_manager();
    if(Tasks::lock_task_manager){
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }

    /*
    std::cout << "hello world!" << std::endl;
    Communication c("127.0.0.1", 8888);

    while(true){
        c.connect_forever();

        std::string output = c.recv_message();
        if(output.length() == 0){
            Error::log_error("connection finished");
        }
        c.send_message("sup brother");
    }*/
}