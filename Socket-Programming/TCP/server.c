#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>

int main()
{
    int serversocket,clientsocket,port; //clientsocket is the socket descriptor , port is the port number
    struct sockaddr_in serveraddr,clientaddr; //creating a structure of type sockaddr_in for server
    socklen_t len; //creating a variable to store the length of the server address 
    char message[100]; 
    serversocket=socket(AF_INET,SOCK_STREAM,0); //creating a socket
    bzero((char*)&serveraddr,sizeof(serveraddr));//initializing the server address to zero
    serveraddr.sin_family=AF_INET;//setting the family of the server address to AF_INET
    printf("Enter the port number ");
    scanf("%d",&port);
    serveraddr.sin_port=htons(port); //setting the port number of the server address to port
    serveraddr.sin_addr.s_addr=INADDR_ANY; //setting the IP address of the server address to INADDR_ANY
    bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr)); //binding the server address to the socket
    bzero((char*)&clientaddr,sizeof(clientaddr)); //initializing the client address to zero
    len=sizeof(clientaddr); //storing the length of the client address in len
    listen(serversocket,5); //listening to the socket, 5 is the number of clients that can connect to the server
    printf("\nWaiting for client connection\n"); 
    clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);//accepting the client connection
    printf("\nClient connectivity received.\n");
    printf("\nReading message from the client.\n");
    read(clientsocket,message,sizeof(message));//reading the message from the client
    printf("\n%s",message);
    printf("\nSending message to the client.\n");
    int msg_len=strlen(message);
    int start = 0, end = msg_len - 1;
	while (start < end) {
		char temp = message[start];
		message[start] = message[end];
		message[end] = temp;
		start++;
		end--;
	}
    write(clientsocket,message,sizeof(message));//sending the message to the client
    close(clientsocket);//closing the client socket
    close(serversocket);//closing the server socket
}