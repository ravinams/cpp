    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <errno.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <pthread.h>

    #define PORT                8408

    #define OPCODE_UPLOAD       'U'
    #define OPCODE_UPLOAD_ACK   'A'
    #define OPCODE_DOWNLOAD     'D'
    #define OPCODE_DOWNLOAD_ACK 'K'

    #define MAGIC_1  'F'
    #define MAGIC_2  'L'

    #define MAX_LINE 1024

    void *worker_thread(void *arg) ;
    int recieveFile(int sockfd, char *fileName, int filesize);

    int main(int argc, char *argv[]) {

        int ret;
        socklen_t len;
        int listenfd = 0 ;
        int connfd = 0;
        struct sockaddr_in serv_addr;
        struct sockaddr_in client_addr ;

        listenfd = socket(AF_INET, SOCK_STREAM, 0);

        if (listenfd < 0) {
        
            printf("socket() error: %s.\n", strerror(errno));
            return -1;
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = (in_port_t)htons(PORT);

        ret = bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

        if (ret < 0)
        {
            printf("bind() error: %s.\n", strerror(errno));
            return -1;
        }

        if (listen(listenfd, 10) < 0)
        {
            printf("listen() error: %s.\n", strerror(errno));
            return -1;
        }


        while (1) {

            printf("waiting for connection...\n");
            len = sizeof(client_addr);
            connfd = accept(listenfd,(struct sockaddr*) &client_addr,&len);

            if (connfd < 0) {
                printf("accept() error: %s.\n", strerror(errno));
                return -1;
            }
            printf("conn accept - %s.\n", inet_ntoa(client_addr.sin_addr));

            pthread_t tid;
            pthread_create(&tid, NULL, worker_thread, (void *)(long)connfd); 
        }
        return 0;
    }

    void *worker_thread(void *arg) {

        int ret;
        int connfd = (int) (long)arg; 
        char recv_buffer[1024]={0};
        printf("[%d] worker thread started.\n", connfd);

        while(1)
        {

        ret = recv(connfd, recv_buffer, 8, 0);

      if (ret < 0) { // Input / output error. 
         printf("[%d] recv() error: %s.\n", connfd, strerror(errno));
         return NULL;
      } else if (ret == 0) { // The connection is terminated by the other end. 
          printf("[%d] connection lost\n", connfd);
       break;
    }
      
        printf(" recv_buffer :  [%c] [%c] [%c] [%d] %d \n", recv_buffer[0],recv_buffer[1],recv_buffer[2],recv_buffer[3],ret);
        
        char opcode = recv_buffer[2] ;

        int file_name_len = recv_buffer[3]+0;

        unsigned int fileLength=0 ;
        fileLength = *(unsigned int*)(recv_buffer+4);
       
        printf(" fileLength :  [%d]  \n",fileLength);
  
        char file_name[128] ={0};
        ret = recv(connfd, file_name, file_name_len, 0);

        printf(" file_name :  [%s]  %d\n",file_name, ret);
        
        if ( recieveFile(connfd,file_name,fileLength) )
        {
            printf("Succesfully recieved file and saved to disk \n"); 
        }
        else
        {
           printf("Failed to recieve file or write to desk\n"); 
        }

        //  if ((int)recv_buffer[2] == OPCODE_UPLOAD)
        //     printf("upload\n");        
        // else if ((int)recv_buffer[2] == OPCODE_DOWNLOAD)
        //      printf("upload\n"); 
        // else
        //     printf("Invalid OPCODE\n"); 
        }

        printf("[%d] worker thread terminated..\n", connfd);
        close(connfd) ;
        pthread_exit(NULL);

     }


int recieveFile(int sockfd, char * fileName, int filesize)
{
    
    FILE *fp = fopen(fileName, "wb");
    if (fp == NULL) 
    {
        perror("Can't open file");
        return 0 ;
    }

    ssize_t total=0;
    ssize_t n;
    char buff[MAX_LINE] = {0};
    ssize_t readSize = filesize < MAX_LINE ? filesize : MAX_LINE ;
    while ((n = recv(sockfd, buff, readSize, 0)) > 0) 
    {
        total+=n;
        if (n == -1)
        {
            perror("Receive File Error");
            return 0 ;
        }
        
        if (fwrite(buff, sizeof(char), n, fp) != n)
        {
            perror("Write File Error");
            return 0 ;
        }
        memset(buff, 0, MAX_LINE);
        readSize = ( filesize - total ) < MAX_LINE ? ( filesize - total ) : MAX_LINE ;
        fflush(fp) ;
    }

 if (fp != NULL) 
    fclose(fp);
  return 1  ; // successfully written to file
}
