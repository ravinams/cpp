// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <errno.h>
  
#define PORT     8080 
#define MAXLINE  200 
#define MAGIC_1  'F'
#define MAGIC_2  'L'
#define OPCODE_POST 'P'
#define OPCODE_RETRIEVE 'R'

  
// Driver code 
int main() { 
    int ret ;
    int sockfd; 
    struct sockaddr_in     servaddr; 
    char send_buffer[1024];
    char recv_buffer[1024];
    char user_input[1024];
    int recv_len;
    socklen_t len;
  
    sockfd = socket ( AF_INET , SOCK_DGRAM , 0);
    if (sockfd < 0) {
         printf("socket() error: %s.\n", strerror(errno));
       return -1;
      }
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = (in_port_t)htons(PORT); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //  // Bind the socket with the server address 
    // if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) 
    // { 
    //     perror("bind failed"); 
    //     exit(EXIT_FAILURE); 
    // } 
 
    while(1)

    {

    printf("\nEnter the text to be sent to server (post#some_text or retrieve#) \n");
    fgets( user_input ,sizeof(user_input),stdin);
    strtok(user_input, "\n");// ignore thew new line char from input
  

    send_buffer[0] = MAGIC_1; // These are constants you defined.
    send_buffer[1] = MAGIC_2;
    int user_input_text_len = 0 ;
    if ( (strncmp(user_input, "post#", 5) == 0) && strlen(user_input) > 5  ) 
    {
     
      user_input_text_len = strlen(user_input) - 5 ;        
      send_buffer[2] = OPCODE_POST;
      send_buffer[3] = user_input_text_len+'0';      
      memcpy(send_buffer+4, user_input+5, user_input_text_len);
     
    }
    else if ( strncmp(user_input, "retrieve#", 9) == 0 && strlen(user_input) == 9 )
    {
         send_buffer[2] = OPCODE_RETRIEVE;
         send_buffer[3] = 0+'0';   
       
    }
    else
    {
      printf("Error: Unrecognized command format\n");
      continue ; // uncomment after while loop ;
      //return -1 ;  // comment after while loop ;
      
    }

    // printf("Message  = %s.\n",send_buffer); 
    ret=sendto(sockfd, send_buffer, strlen(send_buffer)+1, 0, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
   
  
  if (ret <= 0) {
        printf("sendto() error: %s.\n", strerror(errno));
        return -1;
      }

    recv_len = recvfrom(sockfd, (char *)recv_buffer, MAXLINE, 0, (struct sockaddr *) &servaddr, &len); 

    if (recv_len <= 0) {
         printf("recvfrom() error: %s.\n", strerror(errno));
     return -1;
   }

    recv_buffer[recv_len] = '\0'; 
    // printf("From Server :%s\n ",recv_buffer );

    if (strncmp(recv_buffer, "POST_ACK#", 9) == 0)
    {
      printf("post_ack#successful\n");
    }
    else if (strncmp(recv_buffer, "RETRIEVE_ACK#", 13) == 0)
    {
      char retrieved_text[201] ;
      memcpy(retrieved_text, recv_buffer+13, strlen(recv_buffer)-13);
      printf("retrieve_ack#%s\n",retrieved_text);
    }

     memset(send_buffer, 0, MAXLINE+1);
     memset(recv_buffer, 0, MAXLINE+1);

   }
    close(sockfd); 
    return 0; 
} 