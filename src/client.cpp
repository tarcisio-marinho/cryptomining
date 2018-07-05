// #include "communication.h"
// #include "tasks.h"
#include <iostream>
#include <stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
#include <pwd.h>
#include <sys/stat.h>


typedef struct pool_info{
    char * pool, *id;
}pool_info;


pool_info* get_pool_info(){
    char * get_pool = "python3 communication.py get_pool";
    
    int ret = system(get_pool);
    if(ret != 0){
        std::cout << "Erro" << std::endl;
        exit(-1);
    }
    pool_info *pool = (pool_info*) malloc(sizeof(pool_info));
    pool->id = (char *) malloc(sizeof(char) * 500);
    pool->pool =(char *) malloc(sizeof(char) * 500);

    FILE *f = fopen("mining_pool_info_file.txt", "r");
    fscanf(f, "%s", pool->id);
    fscanf(f, "%s", pool->pool);
    fclose(f);
    return pool;
}

char * get_username(){
    struct passwd *pw;
    uid_t uid;
    uid_t NO_UID = -1;
    uid = getuid();

    pw = (uid == NO_UID && 0? NULL: getpwuid(uid));
    return pw->pw_name;
}

char * get_machine_id(){
    FILE * f = fopen("/etc/machine-id", "r");
    char * id = (char *)malloc(32);
    fscanf(f, "%s", id);
    fclose(f);
    return id;
}

void new_miner(){
    char * name = get_username();
    char *id = get_machine_id();
    std::cout << name  << " " << id << std::endl;
}


int main(int argc, char * argv[]){

    //std::thread multithreading(Tasks::check_task_manager); // thread creation
    pool_info * pool= get_pool_info();
    std::cout << pool->id << " " << pool->pool << std::endl;
    new_miner();
    // Tasks::check_task_manager();
    // if(Tasks::lock_task_manager){
    //     std::cout << "true" << std::endl;
    // }else{
    //     std::cout << "false" << std::endl;
    // }

    // desalocate memory
    free(pool->id);
    free(pool->pool);
    free(pool);
    
}