#include "communication.h"

/* Client functions */

void Communication::connect_forever(int port, std::string ip){
   
    struct sockaddr_in address;
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    while(1){
        int rest = 0;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
            printf("\n Socket creation error \n");
            rest = 1;
        }
    
        //memset(&serv_addr, '0', sizeof(serv_addr));
    
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        
        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
            printf("\nInvalid address/ Address not supported \n");
            rest = 1;
        }
    
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
            printf("\nConnection Failed \n");
            rest = 1;
        }

        if(rest == 1){
            printf("Dormindo por 5 segundos");
            sleep(5);
            continue;
        }
        this->sock = sock;
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

    output = interpreter(command);
    return output;
}


void Communication::send_message(char * message){
    //send(sock, message, NULL, 0);
}