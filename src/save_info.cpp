#include "save_info.h"


void Save_info::save_new_connection(char *miner_id){
    char *new_path;
    FILE *f;

    if(Save_info::check_new_connection(miner_id)){
        return;
    }
    char *save_path = "/tmp/cryptominer/";
    new_path = (char*) malloc(strlen(save_path) + strlen(miner_id));
    strcpy(new_path, save_path);
    strcat(new_path, miner_id);
    mkdir(new_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    chdir(new_path);
    f = fopen(miner_id, "w");
    fclose(f);

}


bool Save_info::check_new_connection(char *miner_id){
    char *save_path = "/tmp/cryptominer/";
    char *new_path = (char *) malloc(strlen(save_path) + strlen(miner_id));
    strcpy(new_path, save_path);
    strcat(new_path, miner_id);
    DIR *d;
    
    d = opendir(new_path);
    if(d == NULL){
        closedir(d);
        return false;
    }
    closedir(d);
    return true;

}


void Save_info::create_folder(){
    char *save_path = "/tmp/cryptominer/";
    mkdir(save_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    std::cout << "/tmp/cryptominer/ Created!" << std::endl;
}



void Save_info::log(char *miner_id, char *info){
    char *save_path = "/tmp/cryptominer/";
    char *new_path = (char *) malloc(strlen(save_path) + strlen(miner_id));
    strcpy(new_path, save_path);
    strcat(new_path, miner_id);
    DIR *d;
    
    d = opendir(new_path);
    if(d != NULL){
        FILE *f = fopen(new_path, "r");
        fprintf(f, info);
    }
    closedir(d);
    fclose(f);
}