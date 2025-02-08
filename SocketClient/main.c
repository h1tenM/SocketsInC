#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    // socket file descriptor, 1 param - ipv4, 2 param - TCP, 3 param - 0, bcz we are not specifiying a netwrok layer
    int socketFD = socket(AF_INET,SOCK_STREAM, 0);
        if (socketFD == -1) {
        perror("Socket creation failed");
        return 1;
    }

    char* ip = "142.250.217.110"; // google's
    struct sockaddr_in address; //specific for ipv4
    address.sin_family = AF_INET;
    address.sin_port = htons(80); // port number can be any thing from [0,2^16-1], but we use 80 or 443(hhtp https) bcz google has it specified
    //inet_pton converts the string ip into proper format for the datamemeber of sockaddr, big endian format
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr ); 
    

    int result = connect(socketFD, (struct sockaddr*)&address, sizeof(address)); // had to cast bcz it wantes a general struct
    if(result == 0) printf("connection successfull!");

    return 0;
}


