/* 
 * echoserveri.c - An iterative echo server 
 */ 
#include <ctype.h>
#include "csapp.h"
#include "echo.h"


int main(int argc, char **argv) 
{
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp;
    short client_port;
    if (argc != 2) {
	fprintf(stderr, "usage: %s <port>\n", argv[0]);
	exit(0);
    }
    port = atoi(argv[1]);

    listenfd = Open_listenfd(port);
    while (1) {
	clientlen = sizeof(clientaddr);
	connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

	/* determine the domain name and IP address of the client */
	hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			   sizeof(clientaddr.sin_addr.s_addr), AF_INET);
	haddrp = inet_ntoa(clientaddr.sin_addr);
	client_port = ntohs(clientaddr.sin_port);
	printf("server connected to %s (%s), port %d\n",
	       hp->h_name, haddrp, client_port);
	echo(connfd, "");
	printf("Connection closed\n");
	Close(connfd);
    }
    exit(0);
}
/* $end echoserverimain */
