#ifndef lol
#define lol

#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int createTCPIpv4Socket();
struct sockaddr_in *createIPv4Address(char* ip, int port);

#endif
