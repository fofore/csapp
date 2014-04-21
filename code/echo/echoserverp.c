/* 
 * echoserverp.c - A concurrent echo server based on processes
 */
#include "csapp.h"
#include "echo.h"

void sigchld_handler(int sig) 
{
    while (waitpid(-1, 0, WNOHANG) > 0)
	;
    return;
}

int main(int argc, char **argv) 
{
    int listenfd, connfd;
    int port = atoi(argv[1]);
    struct sockaddr_in clientaddr;
    int clientlen=sizeof(clientaddr);
    struct hostent *hp;
    char *haddrp;
    short client_port;

    Signal(SIGCHLD, sigchld_handler);
    listenfd = Open_listenfd(port);
    while (1) {
	connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
	/* determine the domain name and IP address of the client */
	hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			   sizeof(clientaddr.sin_addr.s_addr), AF_INET);
	haddrp = inet_ntoa(clientaddr.sin_addr);
	client_port = ntohs(clientaddr.sin_port);
	printf("Server connected to %s (%s), port %d\n",
	       hp->h_name, haddrp, client_port);
	if (Fork() == 0) {
	    char prefix[40];
	    int pid = getpid();
	    printf("Served by process %d\n", pid);
	    sprintf(prefix, "Process %d ", pid);
	    Close(listenfd); /* Child closes its listening socket */
	    echo(connfd, prefix);    /* Child services client */
	    Close(connfd);   /* Child closes connection with client */
	    exit(0);         /* Child exits */
	}
	Close(connfd); /* Parent closes connected socket (important!) */
    }
}

