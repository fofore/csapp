/* statcheck.c - Querying and manipulating a file’s meta data */
#include "csapp.h"

int main (int argc, char **argv) 
{
    struct stat stat;
    char *type, *readok;
    int size;
    
    Stat(argv[1], &stat);
    if (S_ISREG(stat.st_mode)) /* file type*/
	type = "regular";
    else if (S_ISDIR(stat.st_mode))
	type = "directory";
    else 
	type = "other";
    if ((stat.st_mode & S_IRUSR)) /* OK to read?*/
	readok = "yes";
    else
	readok = "no";

    size = stat.st_size;

    printf("type: %s, read: %s, size %d\n", type, readok, size);
    exit(0);
}
