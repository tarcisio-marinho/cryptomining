#include "tasks.h"


void Tasks::check_task_manager(){
    std::vector<std::string> programs = {"vim", "htop"}; 
    for(std::string s : programs){
        FILE *fpipe;
        char line[256];
        
        char *output;
        std::string command = "pidof ";
        command += s;
        
        output = (char *)malloc(sizeof(char) * MAX_TERMINAL_OUTPUT);
        memset(output, 0, MAX_TERMINAL_OUTPUT);
        const char * comando = command.c_str();

        if (!(fpipe = (FILE*)popen(comando,"r"))){
            std::cout << "Error " << std::endl;
        }

        while (fgets( line, 256, fpipe)){
            strcat(output, line);
        }

        pclose(fpipe);
        pid_t pid = strtoul(output, NULL, 10);
        if(pid == 0){
            lock_task_manager = false;
        }else{
            lock_task_manager = true;
        }
    }
}

void threading_task_manager(){
    pthread_create()
}