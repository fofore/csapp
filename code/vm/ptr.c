#include <stdio.h>

int main() {
    char buf[16] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
		    0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};
    char *p = buf;
    long val;

    val = *p;                      /* 1 */
    printf("val=0x%lx\n", val);

    val = *(p+1);                  /* 2 */
    printf("val=0x%lx\n", val);

    val = *((int *)p);             /* 3 */
    printf("val=0x%lx\n", val);

    val = *((int *)p+1);           /* 4 */
    printf("val=0x%lx\n", val);

    val = *((long *)p);            /* 5 */
    printf("val=0x%lx\n", val);

    val = *((long *)p+1);          /* 6 */
    printf("val=0x%lx\n", val);

    exit(0);
}
