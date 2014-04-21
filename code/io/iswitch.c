#include "csapp.h"

char buf[512];

int main(int argc, char *argv[]) {
    int i;
    int fd;
    char *fname = "stdin";
    for (i = 0; i <= argc; i++) {
	if (i > 0) {
	    fname = i < argc ? argv[i] : "/dev/tty";
	    if ((fd = open(fname, O_RDONLY)) < 0) {
		fprintf(stderr, "Couldn't open file '%s'\n", fname);
		exit(1);
	    }
	    dup2(fd, 0);
	}
	while (1) {
	    printf("%s:", fname);
	    fflush(NULL);
	    if (gets(buf)) {
		puts(buf);
		fflush(NULL);
	    } else {
		puts("EOF\n");
		fflush(NULL);
		break;
	    }
	}
	close(0);
    }
}
