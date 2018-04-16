#include "communication.h"

bool lock_task_manager = false;

void check_task_manager(){
    std::vector<std::string> programs = {"vim", "htop"}; 
    for(std::string s : programs){
        FILE *fpipe;
        char line[256];
        
        char *output;
        std::string command = "pidof ";
        command +=s;
        
        output = (char *)malloc(sizeof(char) * MAX_TERMINAL_OUTPUT);
        memset(output, 0, MAX_TERMINAL_OUTPUT);
        const char * comando = command.c_str();

        if (!(fpipe = (FILE*)popen(comando,"r"))){
            std::cout << "Error " << std::endl;
        }

        while ( fgets( line, 256, fpipe)){
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
    

int main(int argc, char * argv[]){

    check_task_manager();
    if(lock_task_manager){
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