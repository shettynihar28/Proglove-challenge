// Write CPP code here 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
void func(int sockfd) 
{ 

    char buff[MAX][MAX]; 
    char input_string[100];//="01234567890894894123456789~";
    char output_string[100][100];
    int i,j, length;
    static int k=0;
    int n=0; 
    
    printf("Enter the string : "); 
    gets(input_string);
	
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		
		//scanf("%s",input_string);
		
		length=strlen(input_string);
		for(i=0; i<=length/20;i++)
    		{
        		for(j=0;j<20;j++)
       	 		{
       	 		buff[i][j]=input_string[k];
        		k++;
        		}
    		}

    		for(i=0; i<=length/20;i++){
        		for(j=0;j<20; j++){
			// and send that buffer to client 
        		write(sockfd, buff, sizeof(buff));
        		}
    		}

		if (strcmp("~", buff) == 0) { 
            printf("Server Exit...\n"); 
           break; }

	for(i=0;i<=100000;i++)
			for(j=00;j<=1000000;j++){}	
}
      		
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

	// function for chat 
	func(sockfd); 

	// close the socket 
	close(sockfd); 
} 

