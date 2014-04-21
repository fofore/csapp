/* 
 * echoserverimin.c - A minimal iterative echo server 
 */ 
#include "csapp.h"
#include "echo.h"

int main(int argc, char **argv) 
{
    int listenfd, connfd;
    int port = atoi(argv[1]);
    struct sockaddr_in clientaddr;
    int clientlen = sizeof(clientaddr);
    listenfd = Open_listenfd(port);
    while (1) {
	connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
	echo(connfd, "");
	Close(connfd);
    }
    exit(0);
}

