// Server side implementation of UDP client-server model 
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
    char buffer[MAXLINE]; 
    struct sockaddr_in servaddr, cliaddr; 

    char recv_buffer[1024];
    char send_buffer[1024];
    int recv_len;
    socklen_t len;
      
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    // Filling server information 
    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
      
   
    recv_len = recvfrom(sockfd, (char *)recv_buffer, sizeof(recv_buffer), MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
    recv_buffer[recv_len] = '\0'; 
    printf("From Client :%s\n ",recv_buffer );
    strcpy(send_buffer,"Bye#asfbdfdfdfdfdf from server\0") ;
    printf("--> %s | %d\n",send_buffer,strlen(send_buffer));        
    sendto(sockfd, (const char *)send_buffer, strlen(send_buffer), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, sizeof(cliaddr)); 
    printf("Hello message sent.\n");  
      
    return 0; 
} 