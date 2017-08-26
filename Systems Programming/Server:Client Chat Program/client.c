/****************************************************
//Alan Tsai
//CS283 G3 Network Programming
//8/16/16
//Uses lecture slides as references for threaded chat
****************************************************/
#include "csapp.h"

int main(int argc, char **argv) 
{
    int clientfd;

    char *host, buf[MAXLINE], *port;
    rio_t rio;

	 host = argv[1]; 
	 port = argv[2];

	 clientfd = Open_clientfd(host, port);
	 Rio_readinitb(&rio, clientfd);
	 
	 printf("Enter message:"); fflush(stdout);
	 while (Fgets(buf, MAXLINE, stdin) != NULL)
	 {
		 Rio_writen(clientfd, buf, strlen(buf)); /*send line to server*/
		 Rio_readlineb(&rio, buf, MAXLINE); /*Receive line from server*/
		 printf("Echo: ");
		 Fputs(buf, stdout);
		 printf("Enter message: "); fflush(stdout);
	 }
	 Close(clientfd);
	 exit(0);
}

int Openclientfd(char *hostname, int port)
{
	int clientfd;
	struct hostent *hp;
	struct sockaddr_in serveraddr;

	if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;
	if ((hp = gethostbyname(hostname)) == NULL)
		return -2;

	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char*)hp->h_addr_list[0], (char *)&serveraddr.sin_addr.s_addr,hp -> h_length);
	serveraddr.sin_port = htons(port);

	if(connect(clientfd, (SA*) &serveraddr,sizeof(serveraddr)) < 0)
		return -1;
	return clientfd;
}


