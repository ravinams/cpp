// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT     8080 
#define MAXLINE 1024 
  
// Driver code 
int main() { 
    int sockfd; 
    struct sockaddr_in     servaddr; 
    char send_buffer[1024];
    char recv_buffer[1024];
    char user_input[1024];
    int recv_len;
    socklen_t len;
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
      

    strcpy(send_buffer,"Hello from client\0") ;
    sendto(sockfd, (const char *)send_buffer, strlen(send_buffer), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
    printf("Hello message sent.\n"); 
          
    recv_len = recvfrom(sockfd, (char *)recv_buffer, strlen(recv_buffer), MSG_WAITALL, (struct sockaddr *) &servaddr, &len); 
    recv_buffer[recv_len] = '\0'; 
  
    printf("From Server :%s\n ",recv_buffer );
  
    close(sockfd); 
    return 0; 
} 