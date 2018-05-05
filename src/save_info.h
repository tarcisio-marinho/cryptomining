#ifndef SAVE_INFO_H
#define SAVE_INFO_H
#include <iostream>
#include <sys/stat.h>
#include <cstring>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

class Save_info{
public:
    static void save_new_connection(char *);
    static bool check_new_connection(char *);
    static void create_folder();

    static void log(char *, char *);
};

#endif