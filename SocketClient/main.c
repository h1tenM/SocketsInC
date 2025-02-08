#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "../SocketUtil/Socketutil.h"

int main(){

    int socketFD = createTCPIpv4Socket();

    char* ip = "142.250.217.110"; // google's
    struct sockaddr_in *address = createIPv4Address(ip, 80);

    int result = connect(socketFD, (struct sockaddr*)address, sizeof(*address)); // had to cast bcz it wantes a general struct
    if(result == 0) printf("connection successfull!\n");

    char* message;
    char buffer[1024];
    message = "GET / HTTP/1.1\r\nHost:google.com\r\n\r\n"; // HTTP request string
    send(socketFD, message, strlen(message), 0);

    recv(socketFD, buffer, sizeof(buffer), 0);
    printf("Response was %s\n", buffer);

    return 0;
}


