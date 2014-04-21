#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "csapp.h"

/***
Advice on use.

To run strace, helps to redirect stderr to stdout.  Can do this in bash shell
with:

strace ./hello 2>&1 | grep "write" 

 ***/

int main(int argc, char *argv[])
{
    int buf = 0;
    char string[1024] = "hello\n";
    int c;
    int i;
    while ((c = getopt(argc, argv, "bs:")) != -1) {
	switch(c) {
	case 'b':
	    buf = 1;
	    break;
	case 's':
	    sprintf(string, "%s\n", optarg);
	    break;
	default:
	    printf("Unrecognized command line option '%c'\n", c);
	    exit(0);
	}
    }
    if (buf) {
	char out[2];
	int len = strlen(string);
	for (i = 0; i < len; i++) {
	    sprintf(out, "%c", string[i]);
	    printf(out);
	}
    } else {
	int len = strlen(string);
	for (i = 0; i < len; i++) {
	    Write(1, string+i, 1);
	}
    }
    return 0;
}
