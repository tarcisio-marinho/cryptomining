#include "communication.h"
#include "tasks.h"


int main(int argc, char * argv[]){

    //std::thread multithreading(Tasks::check_task_manager);
    Tasks::check_task_manager();
    if(Tasks::lock_task_manager){
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }

}