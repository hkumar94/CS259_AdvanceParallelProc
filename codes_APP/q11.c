#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define buffer_SIZE 16

int main()
{
    //pipe descriptors
    char mesg[buffer_SIZE];
    char buffer[buffer_SIZE];
    int x,y,m2,y_m2;
    int pipefd[2];
    if(pipe(pipefd) == -1){
        printf("Error");
    }

    //pipe creation successfull
    //write four messages
    printf("\nEnter the message #1 :");
    scanf("%d",&x);
    write(pipefd[1], &x, sizeof(int));
    read(pipefd[0], &y, sizeof(int));
    printf("message #1 received : %d",y);

    //--------------------m2 --------------
    printf("\n\nEnter the message #2 :");
    scanf("%d",&x);
    write(pipefd[1], &x, sizeof(int));
    read(pipefd[0], &y, sizeof(int));
    printf("message #2 received : %d",y);
    //close(pipefd[1]);

    //--------------------m3 --------------
    printf("\n\nEnter the message #3 :");
    scanf("%d",&x);
    write(pipefd[1], &x, sizeof(int));
    read(pipefd[0], &y, sizeof(int));
    printf("message #3 received : %d",y);
    //close(pipefd[1]);

    //--------------------m4 --------------
    printf("\n\nEnter the message #4 :");
    scanf("%d",&x);
    write(pipefd[1], &x, sizeof(int));
    read(pipefd[0], &y, sizeof(int));
    printf("message #4 received : %d",y);
    //close(pipefd[1]);


    return 0;
  
}