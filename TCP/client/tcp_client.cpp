#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT                8501

#define OPCODE_UPLOAD       'U'
#define OPCODE_UPLOAD_ACK   'A'
#define OPCODE_DOWNLOAD     'D'
#define OPCODE_DOWNLOAD_ACK 'K'

#define MAGIC_1  'F'
#define MAGIC_2  'L'

#define MAX_LINE 1024

unsigned int getFileSize(char* fileName) ;
int sendFile(int sockfd, char * fileName, int filesize ) ;
int recieveFile(int sockfd, char * fileName, int filesize) ;

int main(int argc, char *argv[]) {
	int ret;
	int sockfd = 0;
	char send_buffer[1024]={0};
	char user_input[1024]={0};
	struct sockaddr_in serv_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		printf("socket() error: %s.\n", strerror(errno));
		return -1;
	}

	memset(&serv_addr, 0, sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	serv_addr.sin_port = (in_port_t)htons(PORT);
	ret = connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)); 
	if (ret < 0) {
		printf("connect() error: %s.\n", strerror(errno));
		return -1;
	}
	while (1) {
		printf("Please enter the command to be sent to server ( upload$file_name or download$file_name or exit ) ..\n");
		fgets(user_input, sizeof(user_input), stdin);
		strtok(user_input, "\n"); // ignore thew new line char from input

        // printf(" user_input = %s | %d | %d | %d \n",user_input,strlen(user_input),strncmp(user_input, "upload$", 7),strncmp(user_input, "download$", 9));

		if (strncmp(user_input, "exit", 4)==0)
		{
          printf("\n **** Exiting the client. bye...****\n");
          close(sockfd) ;
          break;
		}
		 else if ((strncmp(user_input, "upload$", 7) == 0) && strlen(user_input) > 7)
		 {
		 	
		 	// printf("Upload the file =%s \n",user_input);
    //         fflush(stdout) ;

           char file_name[128]={0};
           int file_name_len =  0;

            file_name_len=strlen(user_input)-7 ;
            memcpy(file_name, user_input+7, file_name_len);

            // printf("command =%s | file_name =%s | file_name_len =%d \n",user_input,file_name,file_name_len);
            unsigned int fileLength=getFileSize(file_name) ; 

            if (fileLength == 0)
            {
               printf("\n **** Either file does not exists or unable to read file content. ****\n");
               continue ; // start the iteration
            }

		 	send_buffer[0] = MAGIC_1; 
		 	send_buffer[1] = MAGIC_2; 
		 	send_buffer[2] = OPCODE_UPLOAD;
            send_buffer[3] = file_name_len; // to convert to string

          
           	memcpy(send_buffer+4, (char*)&fileLength,sizeof(unsigned int));

            send(sockfd, send_buffer, 8, 0); // send the header
            send(sockfd, file_name, file_name_len, 0); // send the file name 

            sendFile(sockfd,file_name,fileLength) ;
            
            //recv(connfd, recv_buffer, 8, 0)
            printf("\nupload_ack$file_upload_successfully! \n\n");

         

		 }
		 else if (strncmp(user_input, "download$", 9) == 0 && strlen(user_input) > 9 )
		 {
		 	
		 	


		 	char file_name[128]={0};
		 	int file_name_len=strlen(user_input)-9 ;
            memcpy(file_name, user_input+9, file_name_len);

            // printf("down the file =%s \n",user_input);
            // fflush(stdout) ;

            send_buffer[0] = MAGIC_1; 
		 	send_buffer[1] = MAGIC_2; 
		 	send_buffer[2] = OPCODE_DOWNLOAD;
            send_buffer[3] = file_name_len; // to convert to string

            send_buffer[4] = '0';
		 	send_buffer[5] = '0';
		 	send_buffer[6] = '0';
            send_buffer[7] = '0';
           
          
            
            send(sockfd, send_buffer, 8, 0); // send the header
            send(sockfd, file_name, file_name_len, 0); // send the file name 

           

            recv(sockfd, send_buffer, 8, 0); // recieve the file length
            unsigned int fileLength = *(unsigned int*)(send_buffer+4);
            // printf("\n File Name =%s ; File Length =%d\n",file_name,fileLength);
		 	recieveFile(sockfd,file_name,fileLength) ;
		 	printf("\ndownload_ack$file_download_successfully!\n");
		 }
		 else
		 {
            printf("\n****Error: Unrecognized command format ( valid format : upload$file_name / download$file_name / exit ) ****\n");
            continue ; // uncomment after while loop ;
		 }
		 memset(send_buffer, 0,1024 );
	}

}

unsigned int getFileSize(char * fileName) 
{
    FILE *fp; /*to create file*/
    long int size=0;
     
    /*Open file in Read Mode*/
    fp=fopen(fileName,"rb");
    if (fp == NULL)
    	return 0 ;
 
    /*Move file point at the end of file.*/
    fseek(fp,0,SEEK_END);
     
    /*Get the current position of the file pointer.*/
    size=ftell(fp);

    if(size==-1) // "There is some ERROR
       size=0;
         
     if (fp != NULL)
     	  fclose(fp) ;
    return size;

}

int sendFile(int sockfd, char * fileName, int filesize ) 
{
   
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) 
    {
        perror("Can't open file");
        return 0 ;
    }


    ssize_t total=0;
    ssize_t n;
    char sendline[MAX_LINE] = {0}; 
   
    while ((n = fread(sendline, sizeof(char), MAX_LINE, fp)) > 0) 
    {
	    total+=n;
        if (n != MAX_LINE && ferror(fp))
        {
            perror("Read File Error");
           return 0 ;
        }
        
        if (send(sockfd, sendline, n, 0) == -1)
        {
            perror("Can't send file");
           return 0 ;
        }
        memset(sendline, 0, MAX_LINE);
        fflush(fp) ;
    }

   if (fp != NULL) 
   	  fclose(fp);

      return 1 ; // successfully send all file .
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
    ssize_t remainingSize = filesize - total ;
    ssize_t readSize = remainingSize < MAX_LINE ? remainingSize : MAX_LINE ;
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
        remainingSize = filesize - total ;

        if (remainingSize == 0) // total file is recievd 
            break ;
        else
           readSize =  remainingSize < MAX_LINE ?  remainingSize : MAX_LINE ;

        fflush(fp) ;
    }

 if (fp != NULL) 
    fclose(fp);
  return 1  ; // successfully written to file
}
