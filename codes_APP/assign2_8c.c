#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
  

void sigintHandler(int sig_num)
{
    //signal(SIGINT, sigintHandler);
    printf("\nJumped to interrup handler\n");
    fflush(stdout);
}
  
int main ()
{
    signal(SIGINT, sigintHandler);

    for (int i = 0 ; i<10;i++)
    {
        printf("Sleep #%d\n",i+1);
        sleep(1);
    }

    printf("Program exiting\n");
    
}