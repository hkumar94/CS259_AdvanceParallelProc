#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
  

void sigintHandler(int sig_num)
{

    signal(SIGINT, sigintHandler);
    printf("\n Ignoring Ctrl+C .. \n");
    fflush(stdout);
}
  
int main ()
{

    signal(SIGINT, sigintHandler);
    printf("Sleep #1\n");
    sleep(1);

    printf("Sleep #2\n");
    sleep(1);

    printf("Sleep #3\n");
    sleep(1);

    printf("Sleep #4\n");
    sleep(1);

    printf("Sleep #5\n");
    sleep(1);

    printf("Program exiting\n");
    
}