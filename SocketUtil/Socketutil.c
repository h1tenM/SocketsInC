#include "Socketutil.h"

int createTCPIpv4Socket(){
    // socket file descriptor, 1 param - ipv4, 2 param - TCP,SOCK_DGRAM for UDP, 3 param - 0, bcz we are not specifiying a netwrok layer
        int socketFD = socket(AF_INET,SOCK_STREAM, 0);
        if (socketFD == -1) {
        perror("Socket creation failed");
        return 1;
    }
    return socketFD;
}

struct sockaddr_in *createIPv4Address(char* ip, int port){

    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in)); //specific for ipv4
    address->sin_family = AF_INET;
    address->sin_port = htons(port); 
 
    //inet_pton converts the string ip into proper format for the datamemeber of sockaddr, big endian format
    inet_pton(AF_INET, ip, &address->sin_addr.s_addr); 
    return address;
}
