#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	printf("here is the %d arguments: %s\n", argc, *argv);
	printf("the argument 2 is %s\n", argv[argc-1]);
	printf("the argument 2 is %s\n", argv[argc]);

	printf("do the commit test");
	return 0;
}
