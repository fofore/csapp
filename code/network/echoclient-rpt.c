/*
 * echoclient.c - An echo client
 */
/* $begin echoclientmain */
#include "csapp.h"

int main(int argc, char **argv) 
{
    int clientfd, port;
    char *host, buf[MAXLINE], msg[MAXLINE];
    rio_t rio;

    int repeat = 1;
    int replicate = 1;
    int i;

    if (argc < 3) {
	fprintf(stderr, "usage: %s <host> <port> [replicate] [repeat]\n", argv[0]);
	exit(0);
    }

    host = argv[1];
    port = atoi(argv[2]);

    if (argc > 3)
      replicate = atoi(argv[3]);

    if (argc > 4)
      repeat = atoi(argv[4]);

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    printf("type:"); fflush(stdout);
    while (Fgets(buf, MAXLINE, stdin) != NULL) {
      int len = strlen(buf);
      int mlen = 0;
      buf[len-1] = '+';
      for (i = 0; i < replicate && mlen+len < MAXLINE; i++) {
	strcpy(msg+mlen, buf);
	mlen += len;
      }
      msg[mlen-1] = '*';
      for (i = 0; i < repeat; i++) {
	if (i == repeat-1) {
	  msg[mlen-1] = '\n';
	}
	printf("starting write #%d ...",  i+1);
	fflush(stdout);
	Rio_writen(clientfd, msg, mlen);
	printf(" writing done\n");
	fflush(stdout);
      }
      Rio_readlineb(&rio, buf, MAXLINE);
      printf("echo:");
      Fputs(buf, stdout);
      printf("type:"); fflush(stdout);	
    }
    Close(clientfd);
    exit(0);
}
/* $end echoclientmain */
