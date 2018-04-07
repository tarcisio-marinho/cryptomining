#ifndef COMUNICATION_H
#define COMUNICATION_H

/* Defines */
#define PORT 8080
#define size 100
#define IP "127.0.0.1"
#define MAX_TERMINAL_OUTPUT 50000
#define err -1


/* Client functions */
int connect_forever();
char * interpreter(char * command);
char * recv_message(int sock);


#endif 
