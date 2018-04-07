#ifndef INCLUDE_H
#define INCLUDE_H

/* Basic stuff */
#include <iostream>
#include <string>
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

#endif