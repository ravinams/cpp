// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <cstdlib> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

  
#define PORT     8080 
#define MAXLINE  200 
#define MAGIC_1  'F'
#define MAGIC_2  'L'
#define OPCODE_POST 'P'
#define OPCODE_RETRIEVE 'R'
  
void logMessages(FILE *fp, char *action, struct sockaddr_in &addr,char* message)
{

if (fp != NULL) 
    { 
       time_t current_time ;
       struct tm *tm ;

       current_time = time(NULL);
       tm = localtime(&current_time);
      // strcat(log_message,"RECIEVE") ;
      // strcat(log_message,asctime(tm)) ;

          int portInt ; char portStr[10] ;
      portInt = ntohs(addr.sin_port);
     snprintf(portStr, sizeof(portStr), "%d", portInt);

        char ipaddress[16];
        inet_ntop(AF_INET, &(addr.sin_addr), ipaddress, 16);

   char * time = asctime(tm);
        time[strlen(time)-1] = '\0';  

      
        fputs(action, fp);  
        fputs("-", fp);        
        fputs(time, fp);    
        fputs(" - [ ", fp);            
        fputs(ipaddress, fp);    
        fputs(" : ", fp);    
        fputs(portStr, fp);    
        fputs(" ] - ", fp);    
        fputs(message, fp);    
        fputs("\n", fp);    
        fflush(fp);
        
    } 
}

// Driver code 
int main() { 
    int ret ;
    int sockfd; 
    char buffer[MAXLINE]; 
    struct sockaddr_in servaddr, cliaddr; 

    char recv_buffer[1024];
    char send_buffer[1024];
    int recv_len;
    socklen_t len;
    char recent_msg[201];

    FILE* logfile; 
    char action[10];

    time_t current_time ;
    struct tm *tm ;

    //ofstream  logfile ;
      
    // Creating socket file descriptor 
   sockfd = socket ( AF_INET , SOCK_DGRAM , 0);
   if (sockfd < 0) {
      printf("socket() error: %s.\n", strerror(errno));
      return -1;
   }
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    //memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    // Filling server information 
    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = (in_port_t)htons(PORT); 
      
    // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // logfile=fopen("tempfile.txt","a");
    // if (logfile == NULL) 
    // { 
    //      printf("\nCannot open a file .......\n");  
    // } 
    // else
    // { 
    //     fputs("ACTION -  TIMESTAMP  - MACHINE - PORT - MESSAGE\n", logfile);    
    //     fflush(logfile);
    //     fclose(logfile); 
    // } 
  

    while(1)
    {
    printf("\nWaiting for the client........\n");
    fflush(stdout) ;
    logfile=fopen("server_messages_log.txt","a");

    len = sizeof(cliaddr);
    recv_len = recvfrom(sockfd, (char *)recv_buffer, sizeof(recv_buffer), 0, ( struct sockaddr *) &cliaddr, &len); 
     if (recv_len <= 0) {
         printf("recvfrom() error: %s.\n", strerror(errno));
     return -1;
    }

    recv_buffer[recv_len] = '\0'; 

    strcpy(action,"RECIEVED");   
    logMessages(logfile,action,cliaddr,recv_buffer) ;
    

   
   if (recv_buffer[0] != MAGIC_1 || recv_buffer[1] != MAGIC_2) {

       strcpy(send_buffer,"Error: Unrecognized MAGIC format\n") ;
      //  printf("Error: Unrecognized MAGIC format\n");
      // // continue ; // uncomment after while loop ;
      // return -1 ;  // comment after while loop ;
   }
   else
   {
      if (recv_buffer[2] == OPCODE_POST) {
        
       
         memset(recent_msg, 0, MAXLINE+1);      
         memcpy(recent_msg, recv_buffer + 4, recv_buffer[3]);       
         strcpy(send_buffer,"POST_ACK#") ;
         
      }
      else if (recv_buffer[2] == OPCODE_RETRIEVE)
      {
        
        strcpy(send_buffer,"RETRIEVE_ACK#") ;
        memcpy(send_buffer+13, recent_msg, sizeof(recent_msg));
      }
      else
      {
        strcpy(send_buffer,"Error: Unrecognized OPCODE format\n") ;
     
      }
   }

    // printf("--> %s | %d\n",send_buffer,strlen(send_buffer));        
    ret=sendto(sockfd, send_buffer, strlen(send_buffer)+1, 0, (const struct sockaddr *) &cliaddr, sizeof(cliaddr)); 
     if (ret <= 0) {
        printf("sendto() error: %s.\n", strerror(errno));
        return -1;
      }

     strcpy(action,"SEND");
     logMessages(logfile,action,cliaddr,send_buffer) ;

    
       memset(send_buffer, 0, MAXLINE+1);
       memset(recv_buffer, 0, MAXLINE+1);

       if (logfile != NULL)
         fclose(logfile); 
   
   }
      
    return 0; 
} 