#ifndef COMUNICATION_H
#define COMUNICATION_H

/* Defines */
#define PORT 8080
#define size 100
#define IP "127.0.0.1"
#define MAX_TERMINAL_OUTPUT 50000
#define err -1

class Communication{

public:
/* Client functions */
void connect_forever(int port, std::string ip);
char * interpreter(char * command);
std::string recv_message(int sock);

private:
    int sock;

};

#endif 
