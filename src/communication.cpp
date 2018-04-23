#include "communication.h"

/* Client functions */

Communication::Communication(char *ip, int port){
    this->ip = ip;
    this->port = port;
    this->sock = err;
}


void Communication::connect_forever(){
   
    struct sockaddr_in address;
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    while(1){
        int rest = 0;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
            Error::log_error("Socket creation error");
            rest = 1;
        }
    
        memset(&serv_addr, '0', sizeof(serv_addr));
    
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(this->port);
        
        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, this->ip, &serv_addr.sin_addr)<=0) {
            Error::log_error("Invalid address/ Address not supported ");
            rest = 1;
        }
    
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
            Error::log_error("\nConnection Failed ");
            rest = 1;
        }

        if(rest == 1){
            Error::log_error("Dormindo por 5 segundos");
            sleep(5);
            continue;
        }
        this->sock = sock;
        return;
    }
}


void Communication::listen_forever(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[size] = {0};        
    while(1){

        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
            Error::log_error("socket failed");
        }
        
        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                    &opt, sizeof(opt))){
            Error::log_error("setsockopt");
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        
        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr *)&address, 
                                    sizeof(address))<0){
            Error::log_error("bind failed");
        }

        if (listen(server_fd, 3) < 0){
            Error::log_error("listen");
        }

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                        (socklen_t*)&addrlen))<0){
            Error::log_error("accept");
        }
        
        this->sock = new_socket;
        return;
    }
}


std::string Communication::recv_message(){

    char command[size] = {0}, *output;
    int bytes_read;

    bytes_read = recv(this->sock , command, size, 0);

    if(bytes_read == 0 || bytes_read == -1){
        /* Server disconnected */
        return NULL;
    }

    return command;
}


void Communication::send_message(char * message){
    send(sock, message, size, 0);

}

std::string Communication::connection_ip(){


    return std::string("MINER INFO - IP - ");    

}

