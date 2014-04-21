#include <stdio.h>
#include <stdlib.h>

#define N (1<<13)

typedef long val_t; 

val_t a[N][N];

int sumarray(val_t a[N][N]) 
{  	
    int i, j;
    val_t sum = 0;

    for (i = 0; i < N; i++) 
	for (j = 0; j < N; j++)
	    sum += a[j][i];
    return sum;	
}

int main()
{
    int i, j;

    for (i = 0; i < N; i++) 
	for (j = 0; j < N; j++)
	    a[i][j] = ((j%2 == 0) ? 1 : -1);

    /* should sum to zero */
    printf("sum=%d\n", sumarray(a));
    exit(0);
}
