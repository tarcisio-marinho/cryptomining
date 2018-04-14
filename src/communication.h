#ifndef COMUNICATION_H
#define COMUNICATION_H

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <unistd.h>

/* Socket interface */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Defines */
#define PORT 8080
#define size 100
#define IP "127.0.0.1"
#define MAX_TERMINAL_OUTPUT 50000
#define err -1

class Communication{

public:
    /* Client functions */
    Communication(char *ip, int port);
    void connect_forever();
    int listen_forever();
    char * interpreter(char * command);
    std::string recv_message();
    void send_message(char * message);

private:
    int sock, port;
    char * ip;

};

#endif 
