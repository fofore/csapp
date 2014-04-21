/*
 * restart.c - A program that restarts itself when you 
 *             type ctrl-c.
 */
#include <stdio.h> 
#include <unistd.h>
#include <signal.h> 
#include <setjmp.h> 

sigjmp_buf buf; 
 
void handler(int sig) { 
    siglongjmp(buf, 1); 
} 
 
int main() { 
    signal(SIGINT, handler); 
  
    if (!sigsetjmp(buf, 1))  
	printf("starting\n"); 
  else  
      printf("restarting\n"); 
 
  
    while(1) { 
	sleep(1); 
	printf("processing...\n"); 
    } 
} 
