/* 
 * echoserveri.c - An iterative echo server 
 */ 
#include <ctype.h>
#include "csapp.h"

/* Destructively modify string to be upper case */
void upper_case(char *s)
{
  while (*s) {
    *s = toupper(*s);
    s++;
  }
}

void echo(int connfd) 
{
    size_t n; 
    char buf[MAXLINE]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
	printf("server received %d bytes\n", (int) n);
	upper_case(buf);
	Rio_writen(connfd, buf, n);
    }
}

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
	echo(connfd);
	printf("Connection closed\n");
	Close(connfd);
    }
    exit(0);
}
/* $end echoserverimain */
