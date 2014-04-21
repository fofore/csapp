/*
 * echoclientub.c - An echo client, with partial buffering of input
 */
/* $begin echoclientmain */
#include "csapp.h"

/* Show what part of line has been read */
void show_partial(char *line, int cnt)
{
  int i;
  printf("[");
  for (i = 0; i < cnt; i++) {
    if (line[i] == '\n')
      printf("\\n");
    else putchar(line[i]);
  }
  printf("]\n");
  fflush(stdout);
}

/* Read a "eline" from stdin and write it back to outfd as single line.
   Eline consists of multiple lines, where final one is empty.
*/

int read_write_line(int outfd) {
  char buf[MAXLINE];
  int eol = 0; /* Have we hit the true end-of-line? */
  int eof = 0;
  while (!eol && !eof) {
    int cnt = 0;
    int c;
    printf("type:"); fflush(stdout);
    while (cnt < MAXLINE) {
      c = getchar();
      if (c == EOF) {
	eof = 1;
	break;
      }
      if (c == '\n') {
	/* End of this line */
	if (cnt) {
	  /* This is just a partial line */
	  break;
	} else {
	  buf[cnt++] = c;
	  eol = 1;
	  break;
	}
      }
      buf[cnt++] = c;
    }
    if (cnt) /* Write back characters */ {
      write(outfd, buf, cnt); /* Should check return code! */
    }
  }
  return (!eof);
}

int main(int argc, char **argv) 
{
    int clientfd, port;
    char *host, buf[MAXLINE];
    rio_t rio;

    if (argc != 3) {
	fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	exit(0);
    }
    host = argv[1];
    port = atoi(argv[2]);
    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    while (read_write_line(clientfd)) {
	Rio_readlineb(&rio, buf, MAXLINE);
	printf("echo:");
	Fputs(buf, stdout);
    }
    Close(clientfd);
    exit(0);
}
/* $end echoclientmain */
