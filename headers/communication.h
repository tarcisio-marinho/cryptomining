#ifndef COMUNICATION_H
#define COMUNICATION_H
#include "include.h"

/* Client functions */
int connect_forever();
char * interpreter(char * command);
char * recv_message(int sock);


#endif 
