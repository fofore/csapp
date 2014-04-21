#include "csapp.h"

char buf[512];

int main(int argc, char *argv[]) {
    int i;
    int fd;
    int savefd = open("/dev/null", O_WRONLY);
    dup2(0, savefd);
    for (i = 1; i <= argc; i++) {
	char *fname = i < argc ? argv[i] : "stdin";
	if (i < argc) {
	    if ((fd = open(fname, O_RDONLY)) < 0) {
		fprintf(stderr, "Couldn't open file '%s'\n", fname);
		exit(1);
	    }
	    dup2(fd, 0);
	} else {
	    dup2(savefd, 0);
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
    return 0;
}

