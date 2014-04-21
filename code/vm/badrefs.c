 #include <stdio.h>
#include <signal.h>

int input_arg;


void handler(int sig) {
    printf("%d: Segmentation fault\n", input_arg);
    fflush(stdout);
    exit(0);
}


int main(int argc, char **argv) {
    volatile int val, *p;

    signal(SIGSEGV, handler);

    if (argc != 2) {
	printf("Usage: %s <k>\n", argv[0]);
	exit(1);
    }
    input_arg = atoi(argv[1]);

    switch (input_arg) {
    case 1: 
	/* Exists, but not allowed to read from kernel space */
	p = (int *)0xf0000000;
	val = *p;
	break;

    case 2:
	/* Exists, but not allowed to write to text area */
	p = (int *) main;
	val = 0;
	*p = val;
	break;

    case 3:
	/* Try to read from a page that does exist */
	p = (int *) main;
	val = *p;
	break;

    case 4:
	/* Try to read from a page that does not exist */
	p = (int *) 0;
	val = *p;
	break;


    default:
	printf("Usage: %s <k>\n", argv[0]);
	exit(1);

    }

    printf("%d: OK\n", input_arg);
    exit(0);
}
