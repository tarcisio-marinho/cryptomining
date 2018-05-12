#include "tasks.h"


void Tasks::check_task_manager(){
    while(true){
        std::vector<std::string> programs = {"top", "htop", "atop", "python3 glances", "pstree"}; 
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
                Error::log_error("Couldnt read terminal output");
            }

            while (fgets( line, 256, fpipe)){
                strcat(output, line);
            }

            pclose(fpipe);
            pid_t pid = strtoul(output, NULL, 10);
            if(pid == 0){
                Tasks::lock_task_manager = false;
            }else{
                Tasks::lock_task_manager = true;
            }
        }
        sleep(2);
    }
}
