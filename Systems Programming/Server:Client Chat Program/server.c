/****************************************************
//Alan Tsai
//CS283 G3 Network Programming
//server.c
//8/16/16
//Uses lecture slides as references for threaded chat
****************************************************/
#include "csapp.h"

void echo(int num);
void openlistendf(int port);

int main(int argc, char **argv)
{
	int listenfd, connfd, port, clientlen;
	struct sockaddr_in clientaddr;
	struct hostent *hp;
	char *haddrp;
	
	port = atoi(argv[1]); /*the server listens on a port passed on the command line*/
	printf("passing port");
	listenfd = Open_listenfd(argv[1]);

	while (1)
	{
		clientlen = sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
				sizeof(clientaddr.sin_addr.s_addr), AF_INET);

		haddrp = inet_ntoa(clientaddr.sin_addr);
		printf("Server connected to %s (%s)\n", hp->h_name, haddrp);
		echo(connfd);
		Close(connfd);
	}
}

int openlistenfd(int port)
{
	int listenfd, optval = 1;
	struct sockaddr_in serveraddr;

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;

	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0)
		return -1;
	
	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)port);
	if(bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr)) < 0)
		return -1;
	
	return listenfd;
}

void echo(int num) 
{
	size_t n; 
	char buf[MAXLINE]; 
	rio_t rio;

	Rio_readinitb(&rio, num);
	while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) 
	{
		//line:netp:echo:eof
		printf("server received %d bytes and the word entered is: %s\n", (int)n, buf);
		Rio_writen(num, buf, n);
	}
}
/* $end echo */

